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

#ifndef INCLUDED_SOFTCAST_GENERAL_SHAPER_H
#define INCLUDED_SOFTCAST_GENERAL_SHAPER_H

#include <softcast/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace softcast {

    /*!
     * \brief <+description of block+>
     * \ingroup softcast
     *
     */
    class SOFTCAST_API general_shaper : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<general_shaper> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of softcast::general_shaper.
       *
       * To avoid accidental use of raw pointers, softcast::general_shaper's
       * constructor is in a private implementation
       * class. softcast::general_shaper::make is the public interface for
       * creating new instances.
       */
      static sptr make(float threshold);
    };

  } // namespace softcast
} // namespace gr

#endif /* INCLUDED_SOFTCAST_GENERAL_SHAPER_H */

