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
#include "tagged_coder_impl.h"

namespace gr {
  namespace softcast {
    const float level = 1.0/64.0;
    tagged_coder::sptr
    tagged_coder::make(const std::string &length_name)
    {
      return gnuradio::get_initial_sptr
        (new tagged_coder_impl(length_name));
    }


    /*
     * The private constructor
     */
    tagged_coder_impl::tagged_coder_impl(const std::string &length_name)
      : gr::tagged_stream_block("tagged_coder",
              gr::io_signature::make(1, 1, sizeof(unsigned char)),
              gr::io_signature::make(1, 1, sizeof(gr_complex)), length_name)
    {
      set_tag_propagation_policy(TPP_DONT);
     }

    /*
     * Our virtual destructor.
     */
    tagged_coder_impl::~tagged_coder_impl()
    {
    }

    int
    tagged_coder_impl::calculate_output_stream_length(const gr_vector_int &ninput_items)
    {
      
			int noutput_items = ninput_items[0];
      return noutput_items;
    }

    int
    tagged_coder_impl::work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
       {
       gr_complex *out = (gr_complex *) output_items[0];
       //const unsigned char *in = (const unsigned char *) input_items[0];
       const char *in = (const char *) input_items[0];

       unsigned int packet_length = ninput_items[0];
       
       
	for(unsigned int i =0; i<packet_length; i++) //very neccessary you have to consume all the input items
        {
         //out[i] = gr_complex((float(in[2*i])-128.0)*level, (float(in[2*i+1])-128.0)*level);
         
         out[i] = gr_complex((float(in[2*i]))*level, (float(in[2*i+1]))*level);
         }
         
      // Tell runtime system how many output items we produced.
      return packet_length;
}
  
  } /* namespace softcast */
} /* namespace gr */

