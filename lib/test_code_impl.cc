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
#include "test_code_impl.h"

namespace gr {
  namespace softcast {
const float level = sqrt(float(0.1));
    const gr_complex symbols[4][4] = {{gr_complex(-1*level,-1*level),gr_complex(-1*level,1*level),gr_complex(-1*level,    
          -3*level),gr_complex(-1*level,3*level)},{gr_complex(1*level,-1*level),gr_complex(1*level,1*level),gr_complex(1*level,-3*level),gr_complex(1*level,3*level)},{gr_complex(-3*level,-1*level),gr_complex(-3*level,1*level),gr_complex(-3*level,-3*level),gr_complex(-3*level,3*level)},{gr_complex(3*level,-1*level),gr_complex(3*level,1*level),gr_complex(3*level,-3*level),gr_complex(3*level,3*level)}};
    test_code::sptr
    test_code::make( )
    {
      return gnuradio::get_initial_sptr
        (new test_code_impl());
    }


    /*
     * The private constructor
     */
    test_code_impl::test_code_impl( )
      : gr::sync_block("test_code",
              gr::io_signature::make(1, 1, sizeof(unsigned char)),
              gr::io_signature::make(1, 1, sizeof(gr_complex)))
    {}

    /*
     * Our virtual destructor.
     */
    test_code_impl::~test_code_impl()
    {
    }

    int
    test_code_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const unsigned char *in = (unsigned char*) input_items[0];
      gr_complex *out = (gr_complex*) output_items[0];
      unsigned char tmp;
      for(int i = 0;i <noutput_items; i++)
        { 
          tmp = in[i];
          out[i] = symbols[tmp & 0x03][((tmp & 0x0C)>>2)];
          }
      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace softcast */
} /* namespace gr */

