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
#include "short_coder_impl.h"

namespace gr {
  namespace softcast {
    const float level = float(1.0/64.0);
    short_coder::sptr
    short_coder::make( )
    {
      return gnuradio::get_initial_sptr
        (new short_coder_impl());
    }


    /*
     * The private constructor
     */
    short_coder_impl::short_coder_impl( )
      : gr::sync_block("short_coder",
              gr::io_signature::make(1, 1, sizeof(unsigned short int)),
              gr::io_signature::make(1, 1, sizeof(gr_complex)))
    {}

    /*
     * Our virtual destructor.
     */
    short_coder_impl::~short_coder_impl()
    {
    }

    int
    short_coder_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const unsigned short int *in = (const unsigned short int *) input_items[0];
      gr_complex *out = (gr_complex *) output_items[0];
      for(int i = 0;i <noutput_items; i++)
        { 
          out[i] = gr_complex((float(in[i] & 0x00FF)-128.0)*level,(float((in[i]&0xFF00)>>8)-128.0)*level);
        }

      return noutput_items;
    }

  } /* namespace softcast */
} /* namespace gr */

