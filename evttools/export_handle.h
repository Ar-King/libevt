/* 
 * Export handle
 *
 * Copyright (c) 2011, Joachim Metz <jbmetz@users.sourceforge.net>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _EXPORT_HANDLE_H )
#define _EXPORT_HANDLE_H

#include <common.h>
#include <file_stream.h>
#include <types.h>

#include <libcstring.h>
#include <liberror.h>

#include "evttools_libevt.h"
#include "log_handle.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct export_handle export_handle_t;

struct export_handle
{
	/* The libevt input file
	 */
	libevt_file_t *input_file;

	/* The nofication output stream
	 */
	FILE *notify_stream;

	/* Value to indicate if abort was signalled
	 */
	int abort;
};

int export_handle_initialize(
     export_handle_t **export_handle,
     liberror_error_t **error );

int export_handle_free(
     export_handle_t **export_handle,
     liberror_error_t **error );

int export_handle_signal_abort(
     export_handle_t *export_handle,
     liberror_error_t **error );

int export_handle_print_data(
     export_handle_t *export_handle,
     FILE *stream,
     const uint8_t *data,
     size_t data_size,
     liberror_error_t **error );

int export_handle_open_input(
     export_handle_t *export_handle,
     const libcstring_system_character_t *filename,
     liberror_error_t **error );

int export_handle_close_input(
     export_handle_t *export_handle,
     liberror_error_t **error );

/* Item specific export functions
 */
int export_handle_export_record(
     export_handle_t *export_handle,
     libevt_item_t *record,
     log_handle_t *log_handle,
     liberror_error_t **error );

/* File export functions
 */
int export_handle_export_items(
     export_handle_t *export_handle,
     libevt_file_t *file,
     log_handle_t *log_handle,
     liberror_error_t **error );

int export_handle_export_file(
     export_handle_t *export_handle,
     log_handle_t *log_handle,
     liberror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif

