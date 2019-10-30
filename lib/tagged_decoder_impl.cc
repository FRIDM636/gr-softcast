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
#include "tagged_decoder_impl.h"

namespace gr {
  namespace softcast {
    const float level = 1.0/64.0;
    tagged_decoder::sptr
    tagged_decoder::make(const std::string &length_name)
    {
      return gnuradio::get_initial_sptr
        (new tagged_decoder_impl(length_name));
    }


    /*
     * The private constructor
     */
    tagged_decoder_impl::tagged_decoder_impl(const std::string &length_name)
      : gr::tagged_stream_block("tagged_decoder",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::make(1, 1, sizeof(unsigned char)), length_name)
    {}

    /*
     * Our virtual destructor.
     */
    tagged_decoder_impl::~tagged_decoder_impl()
    {
    }

    int
    tagged_decoder_impl::calculate_output_stream_length(const gr_vector_int &ninput_items)
    {
      int noutput_items = ninput_items[0];
      return noutput_items ;
    }

    int
    tagged_decoder_impl::work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {

   
       const gr_complex *in = (const gr_complex *) input_items[0];
       //unsigned char *out = (unsigned char  *) output_items[0];
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
    

      // Tell runtime system how many output items we produced.
      return packet_length;
    }

  } /* namespace softcast */
} /* namespace gr */

