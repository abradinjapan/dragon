#ifndef DRAGON__basic
#define DRAGON__basic

/* Include */
// C
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/* Define */
// types
typedef uint8_t ANVIL__u8;
typedef uint16_t ANVIL__u16;
typedef uint32_t ANVIL__u32;
typedef uint64_t ANVIL__u64;
typedef int8_t ANVIL__s8;
typedef int16_t ANVIL__s16;
typedef int32_t ANVIL__s32;
typedef int64_t ANVIL__s64;

// aliases
typedef ANVIL__u8 u8;
typedef ANVIL__u16 u16;
typedef ANVIL__u32 u32;
typedef ANVIL__u64 u64;
typedef ANVIL__s8 s8;
typedef ANVIL__s16 s16;
typedef ANVIL__s32 s32;
typedef ANVIL__s64 s64;
// (ANVIL__current defined later as it requires buffer type)

// pointers
typedef void* ANVIL__address;
#define ANVIL__define__null_address 0
#define ANVIL__define__null_flag 0

// general
typedef ANVIL__u8 ANVIL__character;
typedef ANVIL__u64 ANVIL__file_index;
typedef ANVIL__u64 ANVIL__line_number;
typedef ANVIL__u64 ANVIL__character_index;
typedef ANVIL__u64 ANVIL__tab_count;
typedef ANVIL__u64 ANVIL__length;
typedef ANVIL__u64 ANVIL__bit_count;
typedef ANVIL__u64 ANVIL__byte_count;
#define ANVIL__define__bits_in_byte 8

// lexing types
typedef ANVIL__u8 ANVIL__lexling_type;
typedef ANVIL__address ANVIL__lexling_address;
typedef ANVIL__lexling_address ANVIL__lexling_start;
typedef ANVIL__lexling_address ANVIL__lexling_end;
typedef ANVIL__u64 ANVIL__lexling_index;
typedef ANVIL__u64 ANVIL__lexling_depth; // used for comments and strings

// other compiler types
typedef ANVIL__u64 ANVIL__argument_index;
typedef ANVIL__u64 ANVIL__io_count;
typedef ANVIL__io_count ANVIL__input_count;
typedef ANVIL__io_count ANVIL__output_count;
typedef ANVIL__u64 ANVIL__accountling_index;
typedef ANVIL__accountling_index ANVIL__variable_index;
typedef ANVIL__accountling_index ANVIL__call_index;
typedef ANVIL__accountling_index ANVIL__offset_index;
typedef ANVIL__accountling_index ANVIL__flag_index;
typedef ANVIL__accountling_index ANVIL__statement_index;
typedef ANVIL__accountling_index ANVIL__header_index;
typedef ANVIL__accountling_index ANVIL__string_index;
typedef ANVIL__u64 ANVIL__abstraction_index;

// strings
char* ANVIL__global__predefined_cell_name_strings[] = {
    "dragon.error_code",
    "dragon.constant.character_byte_size",
    "dragon.constant.character_bit_size",
    "dragon.constant.bits_in_byte",
    "dragon.constant.cell_byte_size",
    "dragon.constant.cell_bit_size",
    "dragon.constant.true",
    "dragon.constant.false",
    "dragon.constant.0",
    "dragon.constant.1",
    "dragon.constant.2",
    "dragon.constant.4",
    "dragon.constant.8",
    "dragon.constant.16",
    "dragon.constant.24",
    "dragon.constant.32",
    "dragon.constant.40",
    "dragon.constant.48",
    "dragon.constant.56",
    "dragon.constant.64",
    "dragon.constant.program_input.start",
    "dragon.constant.program_input.end",
    "dragon.constant.program_output.start",
    "dragon.constant.program_output.end",
    "dragon.stack.start",
    "dragon.stack.current",
    "dragon.stack.end",
};
char* ANVIL__global__predefined_flag_name_strings[] = {
    "dragon.always",
    "dragon.never",
    "dragon.temporary",
};
char* ANVIL__global__argument_type_name_strings[] = {
    "invalid",
    "variable",
    "input_variable",
    "output_variable",
    "body_variable",
    "predefined_variable",
    "offset",
    "flag",
    "flag_user_defined",
    "flag_predefined",
    "boolean",
    "binary",
    "integer",
    "hexadecimal",
    "string",
};
char* ANVIL__global__accountling_call_type_name_strings[] = {
    "dragon.set",
    "dragon.print.integer.signed",
    "dragon.print.integer.unsigned",
    "dragon.print.character",
    "dragon.print.buffer_as_string",
    "dragon.print.binary",
    "dragon.io.cell_to_address",
    "dragon.io.address_to_cell",
    "dragon.io.file_to_buffer",
    "dragon.io.buffer_to_file",
    "dragon.copy",
    "dragon.copy.buffer",
    "dragon.memory.request",
    "dragon.memory.return",
    "dragon.buffer.calculate_length",
    "dragon.cast.cell_to_unsigned_integer_string",
    "dragon.integer.add",
    "dragon.integer.subtract",
    "dragon.integer.multiply",
    "dragon.integer.divide",
    "dragon.integer.modulous",
    "dragon.integer.within_range",
    "dragon.binary.or",
    "dragon.binary.invert",
    "dragon.binary.and",
    "dragon.binary.xor",
    "dragon.binary.shift_higher",
    "dragon.binary.shift_lower",
    "dragon.binary.overwrite",
    "dragon.flag.get",
    "dragon.flag.set",
    "dragon.flag.invert",
    "dragon.flag.or",
    "dragon.flag.and",
    "dragon.flag.xor",
    "dragon.jump",
    "dragon.open.context",
    "dragon.compile",
    "dragon.run",
    "dragon.reset.error_code",
    "dragon.get.program_inputs",
    "dragon.set.program_outputs",
    "dragon.context_buffer.set_inputs",
    "dragon.context_buffer.get_outputs",
};

// program stage type
typedef enum ANVIL__pst {
    // stages
    ANVIL__pst__invalid, // invalid
    ANVIL__pst__lexing, // lexing files
    ANVIL__pst__parsing, // parsing files
    ANVIL__pst__accounting, // semantics for all files
    ANVIL__pst__generating, // building program
    ANVIL__pst__running, // running program

    // count
    ANVIL__pst__COUNT,
} ANVIL__pst;

// boolean type
typedef enum ANVIL__bt {
	ANVIL__bt__false = 0,
	ANVIL__bt__true = 1,
	ANVIL__bt__COUNT = 2,
} ANVIL__bt;

/* Allocation */
// return memory to OS
void ANVIL__close__allocation(ANVIL__address start, ANVIL__address end) {
	// do useless operation to quiet compiler
	end = end;

	// return memory
	free(start);

	return;
}

// ask OS for memory
ANVIL__address ANVIL__open__allocation(ANVIL__length length) {
	// return allocation
	return (ANVIL__address)malloc(length);
}

/* Buffer */
// buffer
typedef struct ANVIL__buffer {
	ANVIL__address start;
	ANVIL__address end;
} ANVIL__buffer;

// close buffer
void ANVIL__close__buffer(ANVIL__buffer buffer) {
	// close allocation
	ANVIL__close__allocation(buffer.start, buffer.end);

	return;
}

// create buffer to have specific exact contents
ANVIL__buffer ANVIL__create__buffer(ANVIL__address start, ANVIL__address end) {
	ANVIL__buffer output;

	// setup output
	output.start = start;
	output.end = end;

	return output;
}

// aliase defines
typedef ANVIL__buffer ANVIL__current;

// create buffer in it's standard null setup
ANVIL__buffer ANVIL__create_null__buffer() {
	// return standard null buffer
	return ANVIL__create__buffer(ANVIL__define__null_address, ANVIL__define__null_address);
}

// calculate buffer length
ANVIL__length ANVIL__calculate__buffer_length(ANVIL__buffer buffer) {
    return (ANVIL__length)((u8*)buffer.end - (u8*)buffer.start) + 1;
}

// check to see if the pointers in the buffers are equal
ANVIL__bt ANVIL__calculate__buffer_addresses_equal(ANVIL__buffer a, ANVIL__buffer b) {
    return (ANVIL__bt)((a.start == b.start) && (a.end == b.end));
}

// check to see if the contents in the buffers are identical
ANVIL__bt ANVIL__calculate__buffer_contents_equal(ANVIL__buffer a, ANVIL__buffer b) {
    // check if names are same length
    if (ANVIL__calculate__buffer_length(a) != ANVIL__calculate__buffer_length(b)) {
        // not same length so not identical
        return ANVIL__bt__false;
    }

    // get pointers
    ANVIL__address a_current = a.start;
    ANVIL__address b_current = b.start;

    // check each character
    while (a_current <= a.end) {
        // check character
        if (*(ANVIL__character*)a_current != *(ANVIL__character*)b_current) {
            // character not identical, string not identical
            return ANVIL__bt__false;
        }

        // next characters
        a_current += sizeof(ANVIL__character);
        b_current += sizeof(ANVIL__character);
    }

    // no issues found, buffers are identical
    return ANVIL__bt__true;
}

ANVIL__bt ANVIL__calculate__buffer_starts_with_buffer(ANVIL__buffer searching_in, ANVIL__buffer searching_for) {
    // ensure search is larger than the buffer
    if (ANVIL__calculate__buffer_length(searching_in) < ANVIL__calculate__buffer_length(searching_for)) {
        // not bigger or equal, thus impossible to contain
        return ANVIL__bt__false;
    }

    return ANVIL__calculate__buffer_contents_equal(searching_for, ANVIL__create__buffer(searching_in.start, searching_in.start + ANVIL__calculate__buffer_length(searching_for) - 1));
}

// calculate buffer contains range
ANVIL__bt ANVIL__calculate__buffer_range_in_buffer_range_inclusive(ANVIL__buffer outside, ANVIL__buffer inside) {
    // return calculation
    return (outside.start <= inside.start) && (outside.end >= inside.end);
}

// check to see if it is an empty buffer
ANVIL__bt ANVIL__check__empty_buffer(ANVIL__buffer buffer) {
    // return calculation
    return (ANVIL__bt)(buffer.start == ANVIL__define__null_address);
}

// open buffer
ANVIL__buffer ANVIL__open__buffer(ANVIL__length length) {
	ANVIL__buffer output;

	// attempt allocation
	output.start = ANVIL__open__allocation(length);

	// set end of buffer according to allocation success
	if (output.start != ANVIL__define__null_address) {
		output.end = (ANVIL__address)((((ANVIL__u64)output.start) + length) - 1);
	} else {
		output.end = ANVIL__define__null_address;
	}

	return output;
}

// check if buffers are the same size
ANVIL__bt ANVIL__calculate__are_buffers_same_size(ANVIL__buffer a, ANVIL__buffer b) {
    // return calculation
    return (ANVIL__bt)((a.end - a.start) == (b.end - b.start));
}

// copy buffer
void ANVIL__copy__buffer(ANVIL__buffer source, ANVIL__buffer destination, ANVIL__bt* error) {
    // check for invalid buffer
    if (ANVIL__calculate__are_buffers_same_size(source, destination) == ANVIL__bt__true) {
        // copy buffer
        for (ANVIL__length byte_index = 0; byte_index < (ANVIL__length)(destination.end - destination.start) + 1; byte_index++) {
            // copy byte
            ((ANVIL__u8*)destination.start)[byte_index] = ((ANVIL__u8*)source.start)[byte_index];
        }
    } else {
        // set error
        *error = ANVIL__bt__true;
    }

    return;
}

// create or open a buffer from a string literal (can either duplicate buffer or simply reference original) (can opt out of null termination)
ANVIL__buffer ANVIL__open__buffer_from_string(u8* string, ANVIL__bt duplicate, ANVIL__bt null_terminate) {
    ANVIL__buffer output;
    ANVIL__length length;

    // setup length
    length = 0;

    // get buffer length
    while (string[length] != 0) {
        length++;
    }

    // optionally append null termination
    if (null_terminate == ANVIL__bt__true) {
        length++;
    }

    // reference or duplicate
    if (duplicate == ANVIL__bt__true) {
        // attempt allocation
        output = ANVIL__open__buffer(length);

        // check for null allocation
        if (output.start == ANVIL__define__null_address) {
            // return empty buffer
            return output;
        }

        // copy buffer byte by byte
        for (ANVIL__length byte_index = 0; byte_index < length; byte_index++) {
            // copy byte
            ((ANVIL__u8*)output.start)[byte_index] = string[byte_index];
        }
    } else {
        // setup duplicate output
        output.start = string;
        output.end = string + length - 1;
    }

    return output;
}

// read buffer
ANVIL__u64 ANVIL__read__buffer(ANVIL__address source, ANVIL__length byte_amount) {
	ANVIL__u64 output;

	// setup output
	output = 0;

	// read buffer
	for (ANVIL__u64 byte_index = 0; byte_index < byte_amount; byte_index += 1) {
		// get byte
		((ANVIL__u8*)&output)[byte_index] = ((ANVIL__u8*)source)[byte_index];
	}

	// return output
	return output;
}

// write buffer
void ANVIL__write__buffer(ANVIL__u64 source, ANVIL__length byte_amount, ANVIL__address destination) {
	// write data to buffer
	for (ANVIL__length byte_index = 0; byte_index < byte_amount; byte_index += 1) {
		// write byte
		((ANVIL__u8*)destination)[byte_index] = ((ANVIL__u8*)&source)[byte_index];
	}
	
	return;
}

// append null termination
ANVIL__buffer ANVIL__add__null_termination_to_file_path(ANVIL__buffer file_path, ANVIL__bt* error_occured) {
    ANVIL__buffer output;

    // allocate buffer
    output = ANVIL__open__buffer(ANVIL__calculate__buffer_length(file_path) + 1);

    // copy buffer
    ANVIL__copy__buffer(file_path, ANVIL__create__buffer(output.start, output.end - 1), error_occured);

    // append null termination
    *((ANVIL__character*)output.end) = 0;

    return output;
}

// create buffer from file
ANVIL__buffer ANVIL__move__file_to_buffer(ANVIL__buffer file_path) {
	ANVIL__buffer output;
	FILE* file_handle;
	ANVIL__u64 file_size;
    ANVIL__buffer null_terminated_file_path = file_path;
    ANVIL__bt error_occured = ANVIL__bt__false;

    // check for null termination
    if (*(ANVIL__character*)file_path.end != 0) {
        // setup null termination
        null_terminated_file_path = ANVIL__add__null_termination_to_file_path(file_path, &error_occured);
    }

	// open file
	file_handle = fopen((const char*)null_terminated_file_path.start, "rb");

	// check if the file opened
	if (file_handle == 0) {
		// if not, return empty buffer
		return ANVIL__create_null__buffer();
	}

	// get file size
	fseek(file_handle, 0, SEEK_END);
	file_size = ftell(file_handle);
	fseek(file_handle, 0, SEEK_SET);

	// allocate buffer
	output = ANVIL__open__buffer(file_size);

	// check if buffer allocated
	if (output.start == ANVIL__define__null_address) {
		// close file handle
		fclose(file_handle);

		// return empty buffer
		return output;
	}

	// read file into buffer
	fread(output.start, file_size, 1, file_handle);

	// close file handle
	fclose(file_handle);

    // close null file path if necessary
    if (*(ANVIL__character*)file_path.end != 0) {
        ANVIL__close__buffer(null_terminated_file_path);
    }

	// return buffer
	return output;
}

// create file from buffer
void ANVIL__move__buffer_to_file(ANVIL__bt* error, ANVIL__buffer file_path, ANVIL__buffer data) {
	FILE* file_handle;
    ANVIL__buffer null_terminated_file_path = file_path;

    // check for null termination
    if (*(ANVIL__character*)file_path.end != 0) {
        // setup null termination
        null_terminated_file_path = ANVIL__add__null_termination_to_file_path(file_path, error);
    }

    // setup error to no error to start
    *error = ANVIL__bt__false;

	// open file
	file_handle = fopen((const char*)null_terminated_file_path.start, "w+b");

	// check if the file opened
	if (file_handle == 0) {
		// if not, return error
        *error = ANVIL__bt__true;

		return;
	}

	// write buffer to file
	fwrite(data.start, ANVIL__calculate__buffer_length(data), 1, file_handle);

	// close file handle
	fclose(file_handle);

    // close null file path if necessary
    if (*(ANVIL__character*)file_path.end != 0) {
        ANVIL__close__buffer(null_terminated_file_path);
    }

	// return
	return;
}

// print buffer
void ANVIL__print__buffer(ANVIL__buffer buffer) {
    // print character by character
    for (ANVIL__address character = buffer.start; character <= buffer.end; character += sizeof(ANVIL__character)) {
        // print character
        putchar(*(ANVIL__character*)character);
    }

    return;
}

/* List */
// list types
typedef ANVIL__u64 ANVIL__list_filled_index;
typedef ANVIL__u64 ANVIL__list_increase;

// list object
typedef struct ANVIL__list {
    ANVIL__buffer buffer;
    ANVIL__list_filled_index filled_index;
    ANVIL__list_increase increase;
} ANVIL__list;

// create a list
ANVIL__list ANVIL__create__list(ANVIL__buffer buffer, ANVIL__list_filled_index filled_index, ANVIL__list_increase increase) {
    ANVIL__list output;

    // setup output
    output.buffer = buffer;
    output.filled_index = filled_index;
    output.increase = increase;

    return output;
}

// create a null list
ANVIL__list ANVIL__create_null__list() {
    // return empty list
    return ANVIL__create__list(ANVIL__create_null__buffer(), 0, 0);
}

// open a list
ANVIL__list ANVIL__open__list(ANVIL__list_increase increase, ANVIL__bt* error_occured) {
    ANVIL__list output;
    ANVIL__buffer allocation;

    // allocate list
    allocation = ANVIL__open__buffer(increase);

    // check list validity
    if (allocation.start == ANVIL__define__null_address) {
        // set error
        *error_occured = ANVIL__bt__true;

        // return empty
        return ANVIL__create_null__list();
    // list is valid
    } else {
        // set error to false
        *error_occured = ANVIL__bt__false;
    }

    // setup output
    output.buffer = allocation;
    output.filled_index = 0;
    output.increase = increase;

    return output;
}

// destroy a list
void ANVIL__close__list(ANVIL__list list) {
    // free buffer
    ANVIL__close__buffer(ANVIL__create__buffer(list.buffer.start, list.buffer.end));

    return;
}

// expand a list
void ANVIL__list__expand(ANVIL__list* list, ANVIL__bt* error_occured) {
    ANVIL__list_filled_index new_size;
    ANVIL__buffer new_allocation;

    // calculate new buffer size
    new_size = ((ANVIL__u64)(*list).buffer.end - (ANVIL__u64)(*list).buffer.start + 1) + (*list).increase;

    // request new memory
    new_allocation = ANVIL__open__buffer(new_size);

    // check for failure
    if (new_allocation.start == ANVIL__define__null_address) {
        // set error
        *error_occured = ANVIL__bt__true;

        // return unmodified list
        return;
    }

    // copy old data to new list
    for (ANVIL__list_filled_index i = 0; i < (*list).filled_index; i++) {
        // copy one byte
        ((ANVIL__u8*)new_allocation.start)[i] = ((ANVIL__u8*)(*list).buffer.start)[i];
    }

    // free old buffer
    ANVIL__close__buffer((*list).buffer);

    // setup new list allocation
    (*list).buffer = new_allocation;

    return;
}

// request space for the list
void ANVIL__list__request__space(ANVIL__list* list, ANVIL__byte_count byte_count, ANVIL__bt* error_occured) {
    // expand the list until there is enough space
    while (((ANVIL__u64)(*list).buffer.end - (ANVIL__u64)(*list).buffer.start + 1) < ((*list).filled_index + byte_count)) {
        // expand the list
        ANVIL__list__expand(list, error_occured);

        // check for error
        if (*error_occured == ANVIL__bt__true) {
            // return last modified list
            return;
        }
    }

    return;
}

// add index to address
ANVIL__address ANVIL__calculate__address_from_buffer_index(ANVIL__address start, ANVIL__list_filled_index index) {
    return start + index;
}

// calculate the tip of the list
ANVIL__address ANVIL__calculate__list_current_address(ANVIL__list* list) {
    return ANVIL__calculate__address_from_buffer_index((*list).buffer.start, (*list).filled_index);
}

// calculate the current buffer
ANVIL__buffer ANVIL__calculate__list_current_buffer(ANVIL__list* list) {
    return ANVIL__create__buffer(((*list).buffer.start), ANVIL__calculate__list_current_address(list) - 1);
}

// add a buffer to a list
void ANVIL__list__append__buffer(ANVIL__list* list, ANVIL__buffer buffer, ANVIL__bt* memory_error_occured) {
    // request space
    ANVIL__list__request__space(list, sizeof(ANVIL__buffer), memory_error_occured);

    // append data
    (*(ANVIL__buffer*)ANVIL__calculate__list_current_address(list)) = buffer;

    // increase fill
    (*list).filled_index += sizeof(ANVIL__buffer);

    return;
}

// add a buffer's data to a list
void ANVIL__list__append__buffer_data(ANVIL__list* list, ANVIL__buffer buffer, ANVIL__bt* memory_error_occured) {
    ANVIL__length buffer_length;
    ANVIL__address buffer_old_end;

    // calculate buffer length
    buffer_length = ANVIL__calculate__buffer_length(buffer);

    // calculate old buffer end
    buffer_old_end = (*list).buffer.start + (*list).filled_index - 1;

    // request space
    ANVIL__list__request__space(list, buffer_length, memory_error_occured);

    // append data
    ANVIL__copy__buffer(buffer, ANVIL__create__buffer(buffer_old_end + 1, buffer_old_end + buffer_length), memory_error_occured);

    // increase fill
    (*list).filled_index += buffer_length;

    return;
}

// add a list to a list
void ANVIL__list__append__list(ANVIL__list* list, ANVIL__list data, ANVIL__bt* memory_error_occured) {
    // request space
    ANVIL__list__request__space(list, sizeof(ANVIL__list), memory_error_occured);

    // append data
    (*(ANVIL__list*)ANVIL__calculate__list_current_address(list)) = data;

    // increase fill
    (*list).filled_index += sizeof(ANVIL__list);

    return;
}

// remove a slice of data from a list
void ANVIL__list__erase__space(ANVIL__list* list, ANVIL__list_filled_index range_start_index, ANVIL__list_filled_index range_end_index) {
    ANVIL__buffer old_right;
    ANVIL__buffer new_right;
    ANVIL__bt error;

    // get new right buffer
    old_right = ANVIL__create__buffer(ANVIL__calculate__address_from_buffer_index((*list).buffer.start, range_end_index), ANVIL__calculate__list_current_address(list));
    new_right = ANVIL__create__buffer(old_right.start - (range_end_index - range_start_index + 1), old_right.end - (range_end_index - range_start_index + 1));

    // move data from left to right filling in the gap
    ANVIL__copy__buffer(old_right, new_right, &error);

    // should not happen but handled anyways
    if (error == ANVIL__bt__true) {
        // tell user
        printf("Internal Error: Buffer could not erase data.\n");
    // buffer was clipped, change filled index
    } else {
        // change filled index
        (*list).filled_index -= range_end_index - range_start_index + 1;
    }

    return;
}

// check if two lists are filled up to the same amount
ANVIL__bt ANVIL__calculate__lists_have_same_fill_size(ANVIL__list* a, ANVIL__list* b) {
    return (ANVIL__bt)((*a).filled_index == (*b).filled_index);
}

// take a list and make a standalone buffer
ANVIL__buffer ANVIL__list__open_buffer_from_list(ANVIL__list* list, ANVIL__bt* memory_error_occured) {
    ANVIL__buffer output;

    // allocate output
    output = ANVIL__open__buffer((*list).filled_index);

    // if buffer did not open
    if (ANVIL__check__empty_buffer(output) == ANVIL__bt__true) {
        // set error
        *memory_error_occured = ANVIL__bt__true;
    // if buffer opened
    } else {
        // copy data from list to buffer
        ANVIL__copy__buffer(ANVIL__calculate__list_current_buffer(list), output, memory_error_occured);
    }

    return output;
}

// check if a list is uninitialized
ANVIL__bt ANVIL__check__empty_list(ANVIL__list list) {
    return ANVIL__check__empty_buffer(list.buffer);
}

/* Essentials */
ANVIL__u64 ANVIL__calculate__exponent(ANVIL__u64 base, ANVIL__u64 exponent) {
    ANVIL__u64 output = 1;

    // if zero
    if (exponent == 0) {
        return output;
    }

    // calculate number
    while (exponent > 0) {
        // multiply
        output *= base;

        // next exponent
        exponent--;
    }

    return output;
}

// print tabs
void ANVIL__print__tabs(ANVIL__tab_count tab_count) {
    // print tabs
    while (tab_count > 0) {
        // print tab
        printf("\t");

        // next tab
        tab_count--;
    }

    return;
}


#endif