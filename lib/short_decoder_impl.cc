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
#include "short_decoder_impl.h"

namespace gr {
  namespace softcast {
    const float level = float(1.0/64.0);
    short_decoder::sptr
    short_decoder::make( )
    {
      return gnuradio::get_initial_sptr
        (new short_decoder_impl());
    }


    /*
     * The private constructor
     */
    short_decoder_impl::short_decoder_impl( )
      : gr::sync_block("short_decoder",
              gr::io_signature::make(1,1, sizeof(gr_complex)),
              gr::io_signature::make(1,1, sizeof(unsigned short int)))
    {}

    /*
     * Our virtual destructor.
     */
    short_decoder_impl::~short_decoder_impl()
    {
    }

    int
    short_decoder_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const gr_complex *in = (const gr_complex *) input_items[0];
      unsigned short int *out = (unsigned short int *) output_items[0];
       for(int i = 0;i <noutput_items; i++)
        { 
          out[i] = (int(in[i].imag()/level+128.5)<<8)|int(in[i].real()/level+128.5);
        }
      
      return noutput_items;
    }

  } /* namespace softcast */
} /* namespace gr */

