/* -*- c++ -*- */

#define SOFTCAST_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "softcast_swig_doc.i"

%{
#include "softcast/coder.h"
#include "softcast/decoder.h"
#include "softcast/test_code.h"
#include "softcast/test_decode.h"
#include "softcast/short_coder.h"
#include "softcast/short_decoder.h"
#include "softcast/shaper.h"
#include "softcast/general_shaper.h"
#include "softcast/tagged_coder.h"
#include "softcast/tagged_decoder.h"
%}

%include "softcast/coder.h"
GR_SWIG_BLOCK_MAGIC2(softcast, coder);
%include "softcast/decoder.h"
GR_SWIG_BLOCK_MAGIC2(softcast, decoder);
%include "softcast/test_code.h"
GR_SWIG_BLOCK_MAGIC2(softcast, test_code);
%include "softcast/test_decode.h"
GR_SWIG_BLOCK_MAGIC2(softcast, test_decode);
%include "softcast/short_coder.h"
GR_SWIG_BLOCK_MAGIC2(softcast, short_coder);
%include "softcast/short_decoder.h"
GR_SWIG_BLOCK_MAGIC2(softcast, short_decoder);
%include "softcast/shaper.h"
GR_SWIG_BLOCK_MAGIC2(softcast, shaper);
%include "softcast/general_shaper.h"
GR_SWIG_BLOCK_MAGIC2(softcast, general_shaper);
%include "softcast/tagged_coder.h"
GR_SWIG_BLOCK_MAGIC2(softcast, tagged_coder);
%include "softcast/tagged_decoder.h"
GR_SWIG_BLOCK_MAGIC2(softcast, tagged_decoder);
