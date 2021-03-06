/*
 * Centaurean Density
 *
 * Copyright (c) 2013, Guillaume Voirin
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     1. Redistributions of source code must retain the above copyright notice, this
 *        list of conditions and the following disclaimer.
 *
 *     2. Redistributions in binary form must reproduce the above copyright notice,
 *        this list of conditions and the following disclaimer in the documentation
 *        and/or other materials provided with the distribution.
 *
 *     3. Neither the name of the copyright holder nor the names of its
 *        contributors may be used to endorse or promote products derived from
 *        this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * 11/10/13 02:06
 */

#ifndef DENSITY_FILE_HEADER_H
#define DENSITY_FILE_HEADER_H

#include <stdio.h>
#include <time.h>
#include <utime.h>

#include "globals.h"
#include "block.h"
#include "density_api.h"
#include "memory_teleport.h"
#include "memory_location.h"
#include "memory_teleport.h"

#pragma pack(push)
#pragma pack(4)

typedef struct {
    union {
        uint64_t as_uint64_t;
        density_byte as_bytes[8];
    };
} density_main_header_parameters;

typedef struct {
    density_byte version[3];
    density_byte compressionMode;
    density_byte blockType;
    density_byte reserved[3];
    density_main_header_parameters parameters;
} density_main_header;

#pragma pack(pop)

uint_fast32_t density_main_header_read(density_memory_location *, density_main_header *);

uint_fast32_t density_main_header_write(density_memory_location *, const DENSITY_COMPRESSION_MODE, const DENSITY_BLOCK_TYPE, const density_main_header_parameters);

#endif