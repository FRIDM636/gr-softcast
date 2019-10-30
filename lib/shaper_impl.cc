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
#include "shaper_impl.h"

namespace gr {
  namespace softcast {

    shaper::sptr
    shaper::make(const float threshold)
    {
      return gnuradio::get_initial_sptr
        (new shaper_impl(threshold));
    }


    /*
     * The private constructor
     */
    shaper_impl::shaper_impl(const float threshold)
      : gr::sync_block("shaper",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::make(1, 1, sizeof(gr_complex))),d_threshold(threshold)
    {}

    /*
     * Our virtual destructor.
     */
    shaper_impl::~shaper_impl()
    {
    }

    int
    shaper_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const gr_complex *in = (const gr_complex *) input_items[0];
      gr_complex *out = (gr_complex *) output_items[0];
                for(int i = 0;i <noutput_items; i++) {
          if(in[i].real() > 0)
          out[i].real(in[i].real() > d_threshold ? d_threshold:in[i].real());
          else 
          out[i].real(in[i].real() < -d_threshold ? -d_threshold:in[i].real());
          if(in[i].imag() > 0)
          out[i].imag(in[i].imag() > d_threshold ? d_threshold:in[i].imag());
          else 
          out[i].real(in[i].imag() < -d_threshold ? -d_threshold:in[i].imag());
      }
      

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace softcast */
} /* namespace gr */

