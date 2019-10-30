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

#ifndef INCLUDED_SOFTCAST_CODER_H
#define INCLUDED_SOFTCAST_CODER_H

#include <softcast/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace softcast {

    /*!
     * \brief <+description of block+>
     * \ingroup softcast
     *
     */
    class SOFTCAST_API coder : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<coder> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of softcast::coder.
       *
       * To avoid accidental use of raw pointers, softcast::coder's
       * constructor is in a private implementation
       * class. softcast::coder::make is the public interface for
       * creating new instances.
       */
      static sptr make( );
    };

  } // namespace softcast
} // namespace gr

#endif /* INCLUDED_SOFTCAST_CODER_H */
