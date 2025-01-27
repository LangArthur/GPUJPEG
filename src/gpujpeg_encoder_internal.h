/**
 * @file
 * Copyright (c) 2011-2020, CESNET z.s.p.o
 * Copyright (c) 2011, Silicon Genome, LLC.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef GPUJPEG_ENCODER_INTERNAL_H
#define GPUJPEG_ENCODER_INTERNAL_H

#include "libgpujpeg/gpujpeg_common.h"
#include "libgpujpeg/gpujpeg_encoder.h"
#include "gpujpeg_common_internal.h"
#include "gpujpeg_table.h"
#include "gpujpeg_writer.h"

#ifdef __cplusplus
extern "C" {
#endif

struct gpujpeg_huffman_gpu_encoder;

struct gpujpeg_encoder
{
    /// JPEG coder structure
    struct gpujpeg_coder coder;

    /// JPEG writer structure
    struct gpujpeg_writer* writer;

    /// Quantization tables
    struct gpujpeg_table_quantization table_quantization[GPUJPEG_COMPONENT_TYPE_COUNT];

    /// Huffman coder tables
    struct gpujpeg_table_huffman_encoder table_huffman[GPUJPEG_COMPONENT_TYPE_COUNT][GPUJPEG_HUFFMAN_TYPE_COUNT];

    /// Huffman GPU encoder
    struct gpujpeg_huffman_gpu_encoder * huffman_gpu_encoder;

    /// JPEG header to be emitted
    enum gpujpeg_header_type header_type;

    // Stream
    cudaStream_t stream;
};

#ifdef __cplusplus
}
#endif

#endif // GPUJPEG_ENCODER_INTERNAL_H
