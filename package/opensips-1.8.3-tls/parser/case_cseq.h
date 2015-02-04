/* 
 * $Id: case_cseq.h 9610 2013-01-22 12:19:16Z bogdan_iancu $ 
 *
 * CSeq Header Field Name Parsing Macros
 *
 * Copyright (C) 2001-2003 FhG Fokus
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#ifndef CASE_CSEQ_H
#define CASE_CSEQ_H


#define cseq_CASE          \
     hdr->type = HDR_CSEQ_T; \
     hdr->name.len = 4;    \
     p += 4;               \
     goto dc_cont


#endif /* CASE_CSEQ_H */