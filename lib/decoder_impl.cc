/* -*- c++ -*- */
/*
 * Copyright 2019 gr-softcast author.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "decoder_impl.h"

namespace gr {
  namespace softcast {
	const float level = float(1.0/128.0);
const gr_complex symbols[256] = {gr_complex(level*-128,0),gr_complex(level*-127,0),gr_complex(level*-126,0),gr_complex(level*-125,0),gr_complex(level*-124,0),gr_complex(level*-123,0),gr_complex(level*-122,0),gr_complex(level*-121,0),gr_complex(level*-120,0),gr_complex(level*-119,0),gr_complex(level*-118,0),gr_complex(level*-117,0),gr_complex(level*-116,0),gr_complex(level*-115,0),gr_complex(level*-114,0),gr_complex(level*-113,0),gr_complex(level*-112,0),gr_complex(level*-111,0),gr_complex(level*-110,0),gr_complex(level*-109,0),gr_complex(level*-108,0),gr_complex(level*-107,0),gr_complex(level*-106,0),gr_complex(level*-105,0),gr_complex(level*-104,0),gr_complex(level*-103,0),gr_complex(level*-102,0),gr_complex(level*-101,0),gr_complex(level*-100,0),gr_complex(level*-99,0),gr_complex(level*-98,0),gr_complex(level*-97,0),gr_complex(level*-96,0),gr_complex(level*-95,0),gr_complex(level*-94,0),gr_complex(level*-93,0),gr_complex(level*-92,0),gr_complex(level*-91,0),gr_complex(level*-90,0),gr_complex(level*-89,0),gr_complex(level*-88,0),gr_complex(level*-87,0),gr_complex(level*-86,0),gr_complex(level*-85,0),gr_complex(level*-84,0),gr_complex(level*-83,0),gr_complex(level*-82,0),gr_complex(level*-81,0),gr_complex(level*-80,0),gr_complex(level*-79,0),gr_complex(level*-78,0),gr_complex(level*-77,0),gr_complex(level*-76,0),gr_complex(level*-75,0),gr_complex(level*-74,0),gr_complex(level*-73,0),gr_complex(level*-72,0),gr_complex(level*-71,0),gr_complex(level*-70,0),gr_complex(level*-69,0),gr_complex(level*-68,0),gr_complex(level*-67,0),gr_complex(level*-66,0),gr_complex(level*-65,0),gr_complex(level*-64,0),gr_complex(level*-63,0),gr_complex(level*-62,0),gr_complex(level*-61,0),gr_complex(level*-60,0),gr_complex(level*-59,0),gr_complex(level*-58,0),gr_complex(level*-57,0),gr_complex(level*-56,0),gr_complex(level*-55,0),gr_complex(level*-54,0),gr_complex(level*-53,0),gr_complex(level*-52,0),gr_complex(level*-51,0),gr_complex(level*-50,0),gr_complex(level*-49,0),gr_complex(level*-48,0),gr_complex(level*-47,0),gr_complex(level*-46,0),gr_complex(level*-45,0),gr_complex(level*-44,0),gr_complex(level*-43,0),gr_complex(level*-42,0),gr_complex(level*-41,0),gr_complex(level*-40,0),gr_complex(level*-39,0),gr_complex(level*-38,0),gr_complex(level*-37,0),gr_complex(level*-36,0),gr_complex(level*-35,0),gr_complex(level*-34,0),gr_complex(level*-33,0),gr_complex(level*-32,0),gr_complex(level*-31,0),gr_complex(level*-30,0),gr_complex(level*-29,0),gr_complex(level*-28,0),gr_complex(level*-27,0),gr_complex(level*-26,0),gr_complex(level*-25,0),gr_complex(level*-24,0),gr_complex(level*-23,0),gr_complex(level*-22,0),gr_complex(level*-21,0),gr_complex(level*-20,0),gr_complex(level*-19,0),gr_complex(level*-18,0),gr_complex(level*-17,0),gr_complex(level*-16,0),gr_complex(level*-15,0),gr_complex(level*-14,0),gr_complex(level*-13,0),gr_complex(level*-12,0),gr_complex(level*-11,0),gr_complex(level*-10,0),gr_complex(level*-9,0),gr_complex(level*-8,0),gr_complex(level*-7,0),gr_complex(level*-6,0),gr_complex(level*-5,0),gr_complex(level*-4,0),gr_complex(level*-3,0),gr_complex(level*-2,0),gr_complex(level*-1,0),gr_complex(level*0,0),gr_complex(level*1,0),gr_complex(level*2,0),gr_complex(level*3,0),gr_complex(level*4,0),gr_complex(level*5,0),gr_complex(level*6,0),gr_complex(level*7,0),gr_complex(level*8,0),gr_complex(level*9,0),gr_complex(level*10,0),gr_complex(level*11,0),gr_complex(level*12,0),gr_complex(level*13,0),gr_complex(level*14,0),gr_complex(level*15,0),gr_complex(level*16,0),gr_complex(level*17,0),gr_complex(level*18,0),gr_complex(level*19,0),gr_complex(level*20,0),gr_complex(level*21,0),gr_complex(level*22,0),gr_complex(level*23,0),gr_complex(level*24,0),gr_complex(level*25,0),gr_complex(level*26,0),gr_complex(level*27,0),gr_complex(level*28,0),gr_complex(level*29,0),gr_complex(level*30,0),gr_complex(level*31,0),gr_complex(level*32,0),gr_complex(level*33,0),gr_complex(level*34,0),gr_complex(level*35,0),gr_complex(level*36,0),gr_complex(level*37,0),gr_complex(level*38,0),gr_complex(level*39,0),gr_complex(level*40,0),gr_complex(level*41,0),gr_complex(level*42,0),gr_complex(level*43,0),gr_complex(level*44,0),gr_complex(level*45,0),gr_complex(level*46,0),gr_complex(level*47,0),gr_complex(level*48,0),gr_complex(level*49,0),gr_complex(level*50,0),gr_complex(level*51,0),gr_complex(level*52,0),gr_complex(level*53,0),gr_complex(level*54,0),gr_complex(level*55,0),gr_complex(level*56,0),gr_complex(level*57,0),gr_complex(level*58,0),gr_complex(level*59,0),gr_complex(level*60,0),gr_complex(level*61,0),gr_complex(level*62,0),gr_complex(level*63,0),gr_complex(level*64,0),gr_complex(level*65,0),gr_complex(level*66,0),gr_complex(level*67,0),gr_complex(level*68,0),gr_complex(level*69,0),gr_complex(level*70,0),gr_complex(level*71,0),gr_complex(level*72,0),gr_complex(level*73,0),gr_complex(level*74,0),gr_complex(level*75,0),gr_complex(level*76,0),gr_complex(level*77,0),gr_complex(level*78,0),gr_complex(level*79,0),gr_complex(level*80,0),gr_complex(level*81,0),gr_complex(level*82,0),gr_complex(level*83,0),gr_complex(level*84,0),gr_complex(level*85,0),gr_complex(level*86,0),gr_complex(level*87,0),gr_complex(level*88,0),gr_complex(level*89,0),gr_complex(level*90,0),gr_complex(level*91,0),gr_complex(level*92,0),gr_complex(level*93,0),gr_complex(level*94,0),gr_complex(level*95,0),gr_complex(level*96,0),gr_complex(level*97,0),gr_complex(level*98,0),gr_complex(level*99,0),gr_complex(level*100,0),gr_complex(level*101,0),gr_complex(level*102,0),gr_complex(level*103,0),gr_complex(level*104,0),gr_complex(level*105,0),gr_complex(level*106,0),gr_complex(level*107,0),gr_complex(level*108,0),gr_complex(level*109,0),gr_complex(level*110,0),gr_complex(level*111,0),gr_complex(level*112,0),gr_complex(level*113,0),gr_complex(level*114,0),gr_complex(level*115,0),gr_complex(level*116,0),gr_complex(level*117,0),gr_complex(level*118,0),gr_complex(level*119,0),gr_complex(level*120,0),gr_complex(level*121,0),gr_complex(level*122,0),gr_complex(level*123,0),gr_complex(level*124,0),gr_complex(level*125,0),gr_complex(level*126,0),gr_complex(level*127,0)};

    decoder::sptr
    decoder::make( )
    {
      return gnuradio::get_initial_sptr
        (new decoder_impl());
    }


    /*
     * The private constructor
     */
    decoder_impl::decoder_impl( )
      : gr::block("decoder",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::make(1, 1, sizeof( char)))
    {}

    /*
     * Our virtual destructor.
     */
    decoder_impl::~decoder_impl()
    {
    }

    void
    decoder_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
         ninput_items_required[0] = noutput_items;
    }

    int
    decoder_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
          const gr_complex *in = (const gr_complex *) input_items[0];
          char *out = ( char  *) output_items[0];
    unsigned int packet_length = ninput_items[0];
  float tmp = 0.0;
  
 for(unsigned int  i =0; i <packet_length; i++)
             {  
                /*tmp = in[i].real()/level+128.0;
                if (tmp<0.0)
                out[2*i] = 0;
                else {
                  if(tmp>255)
                     out[2*i] = 255;
                  else
                     out[2*i] = tmp;
                  }
                tmp = in[i].imag()/level+128.0;
                if (tmp<0.0)
                out[2*i+1] = 0;
                else {
                  if(tmp>255)
                     out[2*i+1] = 255;
                  else
                     out[2*i+1] = tmp;
                   }*/

               
              tmp = in[i].real()/level;
                if (tmp < -128.0)
                out[2*i] = (char)(-128);
                else {
                  if(tmp>127.0)
                     out[2*i] = 127;
                  else
                     out[2*i] = tmp;
                  }
                tmp = in[i].imag()/level;
                if (tmp < -128.0)
                out[2*i+1] = (char)(-128);
                else {
                  if(tmp>127.0)
                     out[2*i+1] = 127;
                  else
                     out[2*i+1] = tmp;
                   }
               
              }

      consume_each(noutput_items);
      return noutput_items;
    }

  } /* namespace softcast */
} /* namespace gr */

