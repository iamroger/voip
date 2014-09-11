function message() {
  this.name = ""; //down,move,up,next,tick
  this.x = 0;
  this.y = 0;
  this.ctx  = null;
  this.data = null;
  this.to = function( name ) {
    var r = new message();
	r.name = name;
	r.x = this.x;
	r.y = this.y;
	r.ctx = this.ctx;
	r.data = this.data;
    return r;
  }
}
var message_queue = [];
function state() {
  this.next = [];
  this.self = null;
  this.observer = null;
  this.setObserver = function( o ) {
    this.observer = o;
    return this;
  }
  this.setSelf = function( o ) {
    this.self = o;
    return this;
  }
  this.setTo = function( msg, state ) {
    this.next[msg] = state;
  }
  this.action = function( msg ) {
    return null;
  }
  this.distribute = function( msg ) {
    var n1 = this.next[msg.name];
    //var n2 = this.next[msg.key().prefix()];
    var n3 = this.next["any"];
    if ( n1 !== undefined ) {
      return n1;
    }/*else if( n2 !== null ) {
      return n2;
    }*/else if ( n3 !== undefined ) {
      return n3;
    }
    return null;
  }
  this.move = function( msg ) {
    console.log('move '+JSON.stringify(msg.name));
    var trigger_msg = null;
    var n = this.distribute( msg );  //maybe stack should be added. if left brace, pop it. if right brace, push
    if( n !== null && n !== undefined ) {
      trigger_msg = n.action( msg );
      if( trigger_msg !== null && this.observer != null ) {
        //this.observer.move( trigger_msg );
		message_queue.push( trigger_msg );
      }
      this.self.current = n;
    }
    return trigger_msg;
  }
}

function component_idle() {
  state.call(this);
  this.action = function( msg ) {
    if ( msg.ctx !== null )
      this.self.draw( msg.ctx ); 
  	return null;
  }
}
component_idle.prototype = new state();

function component_rule( that ) {
  var idle = new component_idle().setSelf(that);
  idle.setTo( "any", idle );
  return idle;
}
function component() {
  this.current = new component_rule( this );
  this.name = "com";
  this.rotz = 0;
  this.x = 0;
  this.y = 0;
  this.color = "#FFffff";
  this.grd = null;
  this.vertex = [[0,0],[1,0],[1,1],[0,1]];
  this.draw = function( ctx ) {
    ctx.save(); 
    ctx.beginPath();
	console.log('x '+this.x+' y '+this.y);
    ctx.translate(this.x,this.y);
    ctx.rotate(this.rotz*Math.PI / 180);
	if( this.grd == null ) {
	  this.grd=ctx.createLinearGradient(0,0,1,0);
      this.grd.addColorStop(0,"#FF0000");
      this.grd.addColorStop(1,"#ffffff");
	}
    ctx.fillStyle = this.grd; 
    ctx.scale(this.vertex[2][0],this.vertex[2][1]);	
    ctx.fillRect(0, 0, 1, 1);    
    ctx.restore();    
  };
  this.reset = function() {
  };
  this.scale = function(x,y) {
    this.vertex[1][0] *= x;
    this.vertex[2][0] *= x;
    this.vertex[2][1] *= y;
    this.vertex[3][1] *= y;
  },
  this.rotate = function( z ) {
    this.rotz = z;
  };
  this.position = function( posX, posY ) {
    this.x = posX;
	this.y = posY;
  };
  this.setColor = function( c ) {
    this.color = c;
  };
}

function picture(img,callback){  
  if (img.complete) {
    callback.call(img);  
	return;
  }
  img.onload = function () {
    callback.call(img);
  }
}
function texture(src) {
  component.call(this);
  this.img = new Image();
  this.img.src = src;
  this.draw = function ( ctx ) {
    ctx.save();
    ctx.translate(this.x,this.y);
    ctx.rotate(this.rotz*Math.PI / 180);
    ctx.scale(this.vertex[2][0],this.vertex[2][1]);
    picture(this.img,function(){  
      ctx.drawImage(this,0,0);  
    });
    ctx.restore();
  }
}
texture.prototype = new component();

function text(str) {
  component.call(this);
  this.string = str;
  this.font = "15px Arial";
  this.draw = function ( ctx ) {
    ctx.save();
    ctx.font = this.font;
    console.log('x '+this.x+' y '+this.y);
    ctx.translate(this.x,this.y);
    ctx.rotate(this.rotz*Math.PI / 180);
    ctx.scale(this.vertex[2][0],this.vertex[2][1]);	
    ctx.fillStyle = this.color; 
	  ctx.textBaseline="top";
    ctx.fillText( this.string, 0, 0 );
    ctx.restore();
  };
  this.setFont = function( f ) {
    this.font = f;
  };
  this.setText = function( t ) {
    this.string = t;
  };
}
text.prototype = new component();

function button_hit() {
  state.call(this);
  this.action = function( msg ) { 
    if( msg.x < this.self.x + this.self.vertex[2][0]
      && msg.x > this.self.x
      && msg.y < this.self.y + this.self.vertex[2][1] 
      && msg.y > this.self.y) {
        if ( msg.ctx !== null ){
		  this.self.grd = msg.ctx.createLinearGradient(0,0,1,0);
          this.self.grd.addColorStop(0,"#0000ff");
          this.self.grd.addColorStop(1,"#ffffff");
          this.self.draw( msg.ctx );
        } 
		return msg.to( this.self.name );
      } else {
	    this.self.draw( msg.ctx );
        return null;
      }
  }
}
button_hit.prototype = new state();
function button_idle() {
  state.call(this);
  this.action = function( msg ) {
    //this.parent.bg.setColor("#ffdddddd");
    if ( msg.ctx !== null ){
      this.self.draw( msg.ctx );
    } 
  	return null;
  }
}
button_idle.prototype = new state();

function button_rule( o, that ) {
  var hit = new button_hit().setSelf(that).setObserver(o);
  var idle = new button_idle().setSelf(that).setObserver(o);
  idle.setTo( "tick", idle );
  idle.setTo( "down", hit );
  hit.setTo( "any", idle );
  
  return idle;
}
function button( o ) {
  component.call(this);
  this.txt = new text("");
  this.current = new button_rule( o, this );
  this.position = function( posX, posY ) {
    button.prototype.position.apply(this, arguments);
    this.txt.position( posX, posY );
  };
  this.draw = function(ctx) {
    button.prototype.draw.apply(this, arguments);
    this.txt.draw(ctx);
  };
  this.setText = function(str) {
    this.txt.string = str;
  };
}
button.prototype = new component();

function card_hit() {
  state.call(this);
  this.action = function( msg ) { 
    if( msg.x < this.self.x + this.self.vertex[2][0]
      && msg.x > this.self.x
      && msg.y < this.self.y + this.self.vertex[2][1] 
      && msg.y > this.self.y) {
        if ( this.self.camp == 0 ) {
          this.self.select();
          return null;
        } else {
          this.self.opposite();
          msg.vs = [ this.self.opposition().id, this.self.selection().id ];
          return msg.to( "attack" );
        }
      } else {
	    //this.self.draw( msg.ctx );
        return null;
      }
  }
}
card_hit.prototype = new state();
function card_idle() {
  state.call(this);
  this.action = function( msg ) {
    //this.parent.bg.setColor("#ffdddddd");
    if ( msg.ctx !== null ){
      this.self.draw( msg.ctx );
      if( this.self.iselected() ) {
        this.self.focus( msg.ctx );
		return msg.to("tick");
	  }
    } 
  	return null;
  }
}
card_idle.prototype = new state();
function card_attack() {
  state.call(this);
  this.action = function( msg ) {
    //TODO: net.send( msg );
    //msg.data = [];
    //for( int i = 0 ; i < 10 ; i ++ ) {
    //  msg.data[0].command =
    //}
    return msg.to( "response" );
  }
}
card_attack.prototype = new state();

function fade() {
  this.speed = 0.1;
  this.init = 1;
  this.play = function( ctx, that ) {
    if( this.init != 0 ) {
      this.init -= this.speed;
      ctx.globalAlpha = this.init;
      that.draw();
      ctx.globalAlpha = 1;
      return 1;
    }else {
      this.init = 1;
      return 0;
    }
  }
}

function fade_up() {
  this.speed = 0.1;
  this.init = 1;
  this.y = 0;
  this.play = function( ctx, that, text ) {
    if( this.init != 0 ) {
      this.init -= this.speed;
      this.y += 5;
      ctx.globalAlpha = this.init;
      ctx.font = "15px Arial";
      ctx.translate(that.x,that.y+this.y);
      ctx.fillStyle = this.color;
      ctx.textBaseline="top";
      ctx.fillText( text, 0, 0 );
      ctx.globalAlpha = 1;
      return 1;
    }else {
     this.init = 1;
     return 0;
    }
  }
}

function card_answer() {
  state.call(this);
  this.fade = new fade();
  this.fade_up = new fade_up();
  this.action = function( msg ) {
    if( msg.data[this.self.id].command == "dead" ) {
      if( this.fade.play(msg.ctx, this.self) == 0 ) {
        this.self.set(msg.data[this.self.id]);
        return msg.to("new");
      }
      return msg;
    }else {
      if( this.fade_up.play(msg.ctx, this.self, msg.data[this.self.id].value) ) {
        this.self.set(msg.data[this.self.id]);
        return msg.to("new");
      }
      return msg;
    }
    return null;
  }
}
card_answer.prototype = new state();

function card_rule( o, that ) {
  var hit = new card_hit().setSelf(that).setObserver(o);
  var idle = new card_idle().setSelf(that).setObserver(o);
  var attack = new card_attack().setSelf(that).setObserver(o);
  var answer = new card_answer().setSelf(that).setObserver(o);
  
  idle.setTo( "tick", idle );
  idle.setTo( "down", hit );
  hit.setTo( "any", idle );
  hit.setTo( "attack", attack );
  attack.setTo( "response", answer );
  answer.setTo( "tick", answer );
  answer.setTo( "new", idle );

  return idle;
}
function card( o ) {
  component.call(this);
  this.id = 0;
  this.camp = 0;
  this.deco = new texture("down.png");
  this.step = 2;
  this.photo = new texture("");
  this.current = new card_rule( o, this );
  this.position = function( posX, posY ) {
    this.__proto__.position.call( this, posX, posY );
    this.photo.position( posX, posY );
    this.deco.position(  posX+16, posY - 20 );
  };
  this.iselected = function() {
    return o.selected === this;
  };
  this.select = function() {
    o.selected = this;
  };
  this.opposite = function() {
    o.opposited = this;
  };
  this.opposition = function() {
    return o.opposited;
  };
  this.selection = function() {
    return o.selected;
  };
  this.focus = function(ctx) {
    if( this.deco.y >= this.y - 12 ) {
      this.step = -2;
      this.deco.y = this.y - 12;
    } else if ( this.deco.y <= this.y - 22 ) {
      this.step = 2;
      this.deco.y = this.y - 22;
    }
    this.deco.y += this.step;
      this.deco.draw(ctx);
  };
  this.draw = function(ctx) {
    this.photo.draw(ctx);
  };
  this.setURI = function(str) {
    this.photo.img.src = str;
    
  };
  this.scale = function(w,h) {
    this.__proto__.scale.call( this, 48,48);
    this.photo.scale(w,h);
    //this.deco.scale(0.1,0.1);
  };
}
card.prototype = new component();

function scene_connect( desc ) {
  state.call(this);
  //this.children.clear();
  this.components = [];
  this.components[0] = new text("连接中...");
  this.components[0].color="#FF0000";
  this.action = function( msg ) {
    var r = null;
    for( var i = 0; i < this.components.length && msg.ctx != null; i ++ ) {
      var q = this.components[i].current.move( msg );
      if( q != null ) r = q;
    }
  	return r;
  }
}
scene_connect.prototype = new state();
function scene_select( desc ) {
  state.call(this);
  var d = [["play","小强"],["play","大刘"],["open","新建"]];
  //this.children.clear();
  
  this.components = [];
  for( var i = 0; i < d.length ; i ++ ) {
    this.components[i] = new button( this );
	this.components[i].scale(100,16);
    this.components[i].setText(d[i][1]);
    this.components[i].name = d[i][0];
	this.components[i].position( 0, 10+i*30);
  }
  this.action = function( msg ) {
    var r = null;
    for( var i = 0; i < this.components.length && msg.ctx != null; i ++ ) {
      var q = this.components[i].current.move( msg );
      if( q != null ) r = q;
    }
  	return r;
  }
}
scene_select.prototype = new state();
function scene_open( desc ) {
  state.call(this);
  //this.children.clear();
  this.components = [];
  this.components[0] = new text("请等待对家...");
  this.components[0].color="#FF0000";
  this.action = function( msg ) {
    var r = null;
    for( var i = 0; i < this.components.length && msg.ctx != null; i ++ ) {
      var q = this.components[i].current.move( msg );
      if( q != null ) r = q;
    }
  	return r;
  }
}
scene_open.prototype = new state();
function scene_play( desc ) {
  state.call(this);
  //this.children.clear();
  var d = [["card","c0001",1],["card","c0002",1],["card","c0003",1],["card","c0001",1],["card","c0002",1],["card","c0003",1],
  ["card","c0004",0],["card","c0005",0],["card","c0006",0],["card","c0004",0],["card","c0005",0],["card","c0006",0]];
  var t = 0, b = 0;
  this.opposited = null;
  this.selected = null;
  this.components = [];
  for( var i = 0; i < d.length ; i ++ ) {
    this.components[i] = new card( this );
    this.components[i].setURI("./"+d[i][1]+".png");
	this.components[i].scale(0.5,0.5);
    this.components[i].name = d[i][0];
	if( d[i][2] == 1 ) {
	  this.components[i].position( 10+(t++)*50, 10 );
	  this.components[i].camp = 1;
	}else
	  this.components[i].position( 10+(b++)*50, 100 );
  }
  this.action = function( msg ) {
    var r = null;
    for( var i = 0; i < this.components.length && msg.ctx != null; i ++ ) {
      var q = this.components[i].current.move( msg );
      if( q != null ) r = q;
    }
  	return r;
  }
}
scene_play.prototype = new state();

function scene_rule( that ) {
  var connect = new scene_connect().setSelf(that);
  var select = new scene_select().setSelf(that);
  var play = new scene_play().setSelf(that);
  var open = new scene_open().setSelf(that);
  //connect.setTo( "tick", connect );
  //connect.setTo( "select", select );
  select.setTo( "tick", select );
  select.setTo( "down", select );
  select.setTo( "play", play );
  select.setTo( "open", open );
  play.setTo( "result", select );
  play.setTo( "tick", play );
  play.setTo( "down", play );
  open.setTo( "tick", open );
  open.setTo( "play", play );
  
  return select;
}

function render( canvas, w, h ) {
  var that = this;
  this.current =  new scene_rule( this );
  this.time = 0;
  this.now = 0;
  this.tick = 0;
  this.stop = false;
  this.width = w;
  this.height = h;
  this.X = 0;
  this.Y = 0;
  this.lastmsg = new message();
  this.can = document.getElementById(canvas);
  this.ctx = this.can.getContext("2d");
  //this.queue = [];
  this.loop = function() {
    var v = this.current;
    var msg = message_queue.shift();
    if( v !== null && msg !== null && msg !== undefined ) {
      if( msg.name !== this.lastmsg.name || msg.name === "tick" ) {
        this.ctx.clearRect(0,0,this.width,this.height);
        msg.ctx = this.ctx;
        v.move( msg );
        this.lastmsg = msg;
      }
    } else if( message_queue.length > 2 ) {
      if( message_queue[message_queue.length-1].name === "tick" )
        message_queue.splice(0,message_queue.length-1);
      else
        message_queue.splice(0,message_queue.length);
    }
    if( !this.stop ) {
      //requestAnimationFrame( function(){that.loop()} );
      setTimeout(function(){that.loop()},100);
      this.now = new Date().getTime();
      this.tick = this.now - (this.time || this.now);
      this.time = this.now;
      var msg = new message();
      msg.name = "tick";
      msg.data = this.tick;
      message_queue.push( msg );
    }
  }
  var that = this;
  var downListener = function( evt) {
    var bRect = evt.target.getBoundingClientRect();
	  that.X = (evt.clientX - bRect.left)*(that.can.width/bRect.width);
	  that.Y = (evt.clientY - bRect.top)*(that.can.height/bRect.height);
	  that.can.removeEventListener("mousedown", downListener, false);
	  window.addEventListener("mouseup", upListener, false);

    if (evt.preventDefault) {
      evt.preventDefault();
    } //standard
    else if (evt.returnValue) {
      evt.returnValue = false;
    } //older IE
    var msg = new message();
    msg.name = "down";
    msg.x = that.X;
    msg.y = that.Y;
    message_queue.push( msg );
    return false;
  }
  this.can.addEventListener("mousedown", downListener, false);
  var upListener = function (evt) {
      var bRect = that.can.getBoundingClientRect();
	  that.X = (evt.clientX - bRect.left)*(that.can.width/bRect.width);
	  that.Y = (evt.clientY - bRect.top)*(that.can.height/bRect.height);
	  that.can.addEventListener("mousedown", downListener, false);
	  window.removeEventListener("mouseup", upListener, false);
	  var msg = new message();
      msg.name = "up";
      msg.x = that.X;
      msg.y = that.Y;
      //message_queue.push( msg );
	  return false;
  }
}

