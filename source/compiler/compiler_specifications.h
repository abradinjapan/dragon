#ifndef DRAGON__compiler__specifications
#define DRAGON__compiler__specifications

/* Include */
// anvil instructions
#include "../anvil_coder.h"

/* Define */
// general compiler types
typedef ANVIL__u64 COMPILER__index;
typedef COMPILER__index COMPILER__argument_index;
typedef COMPILER__index COMPILER__io_count;
typedef COMPILER__io_count COMPILER__input_count;
typedef COMPILER__io_count COMPILER__output_count;
typedef COMPILER__index COMPILER__accountling_index;
typedef COMPILER__accountling_index COMPILER__variable_index;
typedef COMPILER__accountling_index COMPILER__variable_type_index;
typedef COMPILER__accountling_index COMPILER__variable_member_index;
typedef ANVIL__u64 COMPILER__blueprintling;
typedef COMPILER__index COMPILER__function_index;
typedef COMPILER__index COMPILER__function_header_index;
typedef COMPILER__index COMPILER__structure_index;
typedef COMPILER__index COMPILER__structure_member_index;
typedef COMPILER__structure_member_index COMPILER__structure_member_count;
typedef ANVIL__buffer COMPILER__structure_handle;
typedef ANVIL__buffer COMPILER__function_handle;
typedef COMPILER__index COMPILER__stack_index;
typedef COMPILER__index COMPILER__offset_index;
typedef COMPILER__index COMPILER__scope_index;
typedef COMPILER__index COMPILER__string_index;
typedef COMPILER__index COMPILER__statement_index;

// definitions
#define COMPILER__define__variable_is_internal_type -1
#define COMPILER__define__variable_name_index_from_name_list 0 // the first index is the variable name, all following names are structure accesses

// master namespace
#define COMPILER__define__master_namespace "dragon"

// accountling statement variable type (used for distinguishing statement inputs and outputs)
typedef enum COMPILER__asvt {
    COMPILER__asvt__input,
    COMPILER__asvt__output,
    COMPILER__asvt__COUNT,
} COMPILER__asvt;

// accountling variable argument type
typedef enum COMPILER__avat {
    COMPILER__avat__master,
    COMPILER__avat__member,
    COMPILER__avat__COUNT,
} COMPILER__avat;

// accounting blueprintling types
typedef enum COMPILER__abt {
    COMPILER__abt__end_blueprint,
    COMPILER__abt__define_type,
    COMPILER__abt__define_function_call,
} COMPILER__abt;

// accountling function header type (a category, NOT the individual built in instructions)
typedef enum COMPILER__afht {
    COMPILER__afht__predefined,
    COMPILER__afht__user_defined,
    COMPILER__afht__COUNT,
} COMPILER__afht;

// parsling argument type
typedef enum COMPILER__pat {
    // start
    COMPILER__pat__START,

    // invalid
    COMPILER__pat__invalid = COMPILER__pat__START,

    // anything that uses name lexlings and possibly colons
    COMPILER__pat__name,

    // offsets
    COMPILER__pat__offset,

    // literals
    COMPILER__pat__string_literal,

    // type
    COMPILER__pat__type,

    // end
    COMPILER__pat__END,

    // count
    COMPILER__pat__COUNT = COMPILER__pat__END - COMPILER__pat__START,
} COMPILER__pat;
char* COMPILER__global__general_argument_type_names[] = {
    "invalid",
    "name",
    "offset",
    "string",
    "type",
};

// all predefined cell names
char* COMPILER__global__predefined_cell_names[] = {
    COMPILER__define__master_namespace ".error",
};

// statement type type
typedef enum COMPILER__stt {
    // invalid
    COMPILER__stt__invalid,

    // statements
    COMPILER__stt__function_call,
    COMPILER__stt__offset,
    COMPILER__stt__subscope,

    // headers
    COMPILER__stt__function_header,
    COMPILER__stt__structure_header,

    // count
    COMPILER__stt__COUNT,
} COMPILER__stt;

// accountling statement type
typedef enum COMPILER__ast {
    // built in calls
    // data insertion
    COMPILER__ast__predefined__set__cell,
    COMPILER__ast__predefined__set__string,

    // print
    COMPILER__ast__predefined__print__debug_cell,
    COMPILER__ast__predefined__print__buffer_as_string,
    COMPILER__ast__predefined__print__cell_as_binary,
    COMPILER__ast__predefined__print__new_line,
    COMPILER__ast__predefined__print__tabs,

    // filling structures
    COMPILER__ast__predefined__copy__anything,
    COMPILER__ast__predefined__pack__anything,
    COMPILER__ast__predefined__pack_null__anything,

    // jumps
    COMPILER__ast__predefined__jump__top,
    COMPILER__ast__predefined__jump__bottom,
    COMPILER__ast__predefined__jump__offset,

    // bits
    COMPILER__ast__predefined__bits_or,
    COMPILER__ast__predefined__bits_invert,
    COMPILER__ast__predefined__bits_and,
    COMPILER__ast__predefined__bits_xor,
    COMPILER__ast__predefined__bits_shift_higher,
    COMPILER__ast__predefined__bits_shift_lower,
    COMPILER__ast__predefined__bits_overwrite,

    // integers
    COMPILER__ast__predefined__check__integer_within_range,
    COMPILER__ast__predefined__integer__addition,
    COMPILER__ast__predefined__integer__subtraction,
    COMPILER__ast__predefined__integer__multiplication,
    COMPILER__ast__predefined__integer__division,
    COMPILER__ast__predefined__integer__modulous,

    // buffers
    COMPILER__ast__predefined__buffer__request,
    COMPILER__ast__predefined__buffer__return,
    COMPILER__ast__predefined__buffer__calculate__length,
    COMPILER__ast__predefined__buffer__calculate__end_address,
    COMPILER__ast__predefined__buffer__calculate__start_address,

    // movers
    COMPILER__ast__predefined__mover__address_to_cell,
    COMPILER__ast__predefined__mover__cell_to_address,
    COMPILER__ast__predefined__mover__file_to_buffer,
    COMPILER__ast__predefined__mover__buffer_to_file,
    COMPILER__ast__predefined__mover__buffer_copy__low_to_high,
    COMPILER__ast__predefined__mover__buffer_copy__high_to_low,

    // file deleters
    COMPILER__ast__predefined__delete_file,

    // list calls
    COMPILER__ast__predefined__list__open_list,
    COMPILER__ast__predefined__list__close_list,
    COMPILER__ast__predefined__list__append__structure,
    COMPILER__ast__predefined__list__append__buffer_data,

    // time
    COMPILER__ast__predefined__time__get_current_time,

    // user defined call
    COMPILER__ast__user_defined_function_call,

    // offsets
    COMPILER__ast__offset,

    // scopes
    COMPILER__ast__scope,
    
    // invalid
    COMPILER__ast__invalid,

    // COUNT
    COMPILER__ast__COUNT,
} COMPILER__ast;

// program stage type
typedef enum COMPILER__pst {
    // stages
    COMPILER__pst__invalid, // invalid
    COMPILER__pst__lexing, // lexing files
    COMPILER__pst__parsing, // parsing files
    COMPILER__pst__accounting, // semantics for all files
    COMPILER__pst__generating, // building program
    COMPILER__pst__running, // running program

    // count
    COMPILER__pst__COUNT,
} COMPILER__pst;

// accountling argument type
typedef enum COMPILER__aat {
    COMPILER__aat__invalid,
    COMPILER__aat__cell_value, // raw value
    COMPILER__aat__string_index, // string
    COMPILER__aat__offset, // offset
    COMPILER__aat__scope, // scope
    COMPILER__aat__variable, // variable / structure member from variable
    COMPILER__aat__COUNT,
} COMPILER__aat;

// predefined types
// names
char* COMPILER__global__predefined_type_names[] = {
    COMPILER__define__master_namespace ".cell",
    COMPILER__define__master_namespace ".buffer",
    COMPILER__define__master_namespace ".list",
    COMPILER__define__master_namespace ".time",
};
// predefined type's member names
const char* COMPILER__global__predefined_type_member_names[] = {
    "value",
    "start",
    "end",
    "allocation",
    "length",
    "increase",
    "seconds",
    "nanoseconds",
    "INTERNAL",
};
// predefined type member name type
typedef enum COMPILER__ptmnt {
    COMPILER__ptmnt__value,
    COMPILER__ptmnt__start,
    COMPILER__ptmnt__end,
    COMPILER__ptmnt__allocation,
    COMPILER__ptmnt__content_length,
    COMPILER__ptmnt__increase,
    COMPILER__ptmnt__seconds,
    COMPILER__ptmnt__nanoseconds,
    COMPILER__ptmnt__COUNT,
} COMPILER__ptmnt;
// predefined type type
typedef enum COMPILER__ptt {
    // start
    COMPILER__ptt__START = 0,

    // type definitions
    COMPILER__ptt__dragon_cell = COMPILER__ptt__START,
    COMPILER__ptt__dragon_buffer,
    COMPILER__ptt__dragon_list,
    COMPILER__ptt__dragon_time,

    // user defined start
    COMPILER__ptt__USER_DEFINED_START,

    // end
    COMPILER__ptt__END = COMPILER__ptt__USER_DEFINED_START,

    // count
    COMPILER__ptt__COUNT = COMPILER__ptt__END - COMPILER__ptt__START,
} COMPILER__ptt;
// blueprint
COMPILER__blueprintling COMPILER__global__predefined_types[] = {
    // cell
    COMPILER__abt__define_type,
        COMPILER__ptt__dragon_cell,
        1,
        COMPILER__define__variable_is_internal_type,
            COMPILER__ptmnt__value,
    // buffer
    COMPILER__abt__define_type,
        COMPILER__ptt__dragon_buffer,
        2,
        COMPILER__ptt__dragon_cell, // start
            COMPILER__ptmnt__start,
        COMPILER__ptt__dragon_cell, // end
            COMPILER__ptmnt__end,
    // list
    COMPILER__abt__define_type,
        COMPILER__ptt__dragon_list,
        3,
        COMPILER__ptt__dragon_buffer, // allocated memory
            COMPILER__ptmnt__allocation,
        COMPILER__ptt__dragon_cell, // filled memory
            COMPILER__ptmnt__content_length,
        COMPILER__ptt__dragon_cell, // increase
            COMPILER__ptmnt__increase,
    // time
    COMPILER__abt__define_type,
        COMPILER__ptt__dragon_time,
        2,
        COMPILER__ptt__dragon_cell,
            COMPILER__ptmnt__seconds, // seconds
        COMPILER__ptt__dragon_cell,
            COMPILER__ptmnt__nanoseconds, // nanoseconds
    COMPILER__abt__end_blueprint,
};

// all predefined function call names
char* COMPILER__global__predefined_function_call_names[] = {
    // set
    COMPILER__define__master_namespace ".set",

    // prints
    COMPILER__define__master_namespace ".print.debug_cell",
    COMPILER__define__master_namespace ".print.buffer_as_string",
    COMPILER__define__master_namespace ".print.cell_as_binary",
    COMPILER__define__master_namespace ".print.new_line",
    COMPILER__define__master_namespace ".print.tabs",

    // moving cells
    COMPILER__define__master_namespace ".copy",
    COMPILER__define__master_namespace ".pack",
    COMPILER__define__master_namespace ".pack.null",

    // jumps
    COMPILER__define__master_namespace ".jump.top",
    COMPILER__define__master_namespace ".jump.bottom",
    COMPILER__define__master_namespace ".jump",

    // bit operations
    COMPILER__define__master_namespace ".bits.or",
    COMPILER__define__master_namespace ".bits.invert",
    COMPILER__define__master_namespace ".bits.and",
    COMPILER__define__master_namespace ".bits.xor",
    COMPILER__define__master_namespace ".bits.shift_higher",
    COMPILER__define__master_namespace ".bits.shift_lower",
    COMPILER__define__master_namespace ".bits.overwrite",

    // integer operations
    COMPILER__define__master_namespace ".integer.within_range",
    COMPILER__define__master_namespace ".integer.add",
    COMPILER__define__master_namespace ".integer.subtract",
    COMPILER__define__master_namespace ".integer.multiply",
    COMPILER__define__master_namespace ".integer.divide",
    COMPILER__define__master_namespace ".integer.modulous",

    // buffer operations
    COMPILER__define__master_namespace ".buffer.request",
    COMPILER__define__master_namespace ".buffer.return",
    COMPILER__define__master_namespace ".buffer.calculate.length",
    COMPILER__define__master_namespace ".buffer.calculate.end_address",
    COMPILER__define__master_namespace ".buffer.calculate.start_address",
    COMPILER__define__master_namespace ".address_to_cell",
    COMPILER__define__master_namespace ".cell_to_address",
    COMPILER__define__master_namespace ".file_to_buffer",
    COMPILER__define__master_namespace ".buffer_to_file",
    COMPILER__define__master_namespace ".buffer.copy.low_to_high",
    COMPILER__define__master_namespace ".buffer.copy.high_to_low",
    COMPILER__define__master_namespace ".delete_file",

    // list operations
    COMPILER__define__master_namespace ".list.open",
    COMPILER__define__master_namespace ".list.close",
    COMPILER__define__master_namespace ".list.append.structure",
    COMPILER__define__master_namespace ".list.append.buffer",

    // time operations
    COMPILER__define__master_namespace ".time.now",
};
// predefined function call name type
typedef enum COMPILER__pfcnt {
    // sets
    COMPILER__pfcnt__set,

    // prints
    COMPILER__pfcnt__print__debug_cell,
    COMPILER__pfcnt__print__buffer_as_string,
    COMPILER__pfcnt__print__cell_as_binary,
    COMPILER__pfcnt__print__new_line,
    COMPILER__pfcnt__print__tabs,

    // moving cells
    COMPILER__pfcnt__copy,
    COMPILER__pfcnt__pack,
    COMPILER__pfcnt__pack_null,

    // jumps
    COMPILER__pfcnt__jump__top,
    COMPILER__pfcnt__jump__bottom,
    COMPILER__pfcnt__jump,

    // bit operations
    COMPILER__pfcnt__bits__or,
    COMPILER__pfcnt__bits__invert,
    COMPILER__pfcnt__bits__and,
    COMPILER__pfcnt__bits__xor,
    COMPILER__pfcnt__bits__shift_higher,
    COMPILER__pfcnt__bits__shift_lower,
    COMPILER__pfcnt__bits__overwrite,

    // integer operations
    COMPILER__pfcnt__integer__within_range,
    COMPILER__pfcnt__integer__add,
    COMPILER__pfcnt__integer__subtract,
    COMPILER__pfcnt__integer__multiply,
    COMPILER__pfcnt__integer__divide,
    COMPILER__pfcnt__integer__modulous,

    // buffer operations
    COMPILER__pfcnt__buffer__request,
    COMPILER__pfcnt__buffer__return,
    COMPILER__pfcnt__buffer__calculate__length,
    COMPILER__pfcnt__buffer__calculate__end_address,
    COMPILER__pfcnt__buffer__calculate__start_address,
    COMPILER__pfcnt__buffer__address_to_cell,
    COMPILER__pfcnt__buffer__cell_to_address,
    COMPILER__pfcnt__buffer__file_to_buffer,
    COMPILER__pfcnt__buffer__buffer_to_file,
    COMPILER__pfcnt__buffer__copy__low_to_high,
    COMPILER__pfcnt__buffer__copy__high_to_low,
    COMPILER__pfcnt__buffer__delete_file,

    // list operations
    COMPILER__pfcnt__list__open,
    COMPILER__pfcnt__list__close,
    COMPILER__pfcnt__list__append__structure,
    COMPILER__pfcnt__list__append__buffer_data,

    // time
    COMPILER__pfcnt__time__now,

    // COUNT
    COMPILER__pfcnt__COUNT,
} COMPILER__pfcnt;
// header blueprint for one off built in functions
COMPILER__blueprintling COMPILER__global__predefined_one_off_function_calls[] = {
    // set cell
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__set__cell,
        COMPILER__pfcnt__set,
        1,
        COMPILER__aat__cell_value,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        
    // set string
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__set__string,
        COMPILER__pfcnt__set,
        1,
        COMPILER__aat__string_index,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_buffer,
    
    // print debug cell
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__print__debug_cell,
        COMPILER__pfcnt__print__debug_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        0,
    
    // print buffer as string
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__print__buffer_as_string,
        COMPILER__pfcnt__print__buffer_as_string,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_buffer,
        0,
    
    // print cell as binary
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__print__cell_as_binary,
        COMPILER__pfcnt__print__cell_as_binary,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        0,
    
    // print new line
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__print__new_line,
        COMPILER__pfcnt__print__new_line,
        0,
        0,
    
    // print tabs
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__print__tabs,
        COMPILER__pfcnt__print__tabs,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        0,

    // jumps
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__jump__top,
        COMPILER__pfcnt__jump__top,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__offset,
        0,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__jump__bottom,
        COMPILER__pfcnt__jump__bottom,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__offset,
        0,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__jump__offset,
        COMPILER__pfcnt__jump,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__offset,
        0,
    
    // bits
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__bits_or,
        COMPILER__pfcnt__bits__or,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__bits_invert,
        COMPILER__pfcnt__bits__invert,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__bits_and,
        COMPILER__pfcnt__bits__and,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__bits_xor,
        COMPILER__pfcnt__bits__xor,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__bits_shift_higher,
        COMPILER__pfcnt__bits__shift_higher,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__bits_shift_lower,
        COMPILER__pfcnt__bits__shift_lower,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__bits_overwrite,
        COMPILER__pfcnt__bits__overwrite,
        3,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    
    // integers
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__check__integer_within_range,
        COMPILER__pfcnt__integer__within_range,
        4,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__integer__addition,
        COMPILER__pfcnt__integer__add,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__integer__subtraction,
        COMPILER__pfcnt__integer__subtract,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__integer__multiplication,
        COMPILER__pfcnt__integer__multiply,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__integer__division,
        COMPILER__pfcnt__integer__divide,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__integer__modulous,
        COMPILER__pfcnt__integer__modulous,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    
    // buffers
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__buffer__request,
        COMPILER__pfcnt__buffer__request,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_buffer,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__buffer__return,
        COMPILER__pfcnt__buffer__return,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_buffer,
        0,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__buffer__calculate__length,
        COMPILER__pfcnt__buffer__calculate__length,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_buffer,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__buffer__calculate__end_address,
        COMPILER__pfcnt__buffer__calculate__end_address,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__buffer__calculate__start_address,
        COMPILER__pfcnt__buffer__calculate__start_address,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    
    // movers
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__mover__address_to_cell,
        COMPILER__pfcnt__buffer__address_to_cell,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__mover__cell_to_address,
        COMPILER__pfcnt__buffer__cell_to_address,
        3,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        0,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__mover__file_to_buffer,
        COMPILER__pfcnt__buffer__file_to_buffer,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_buffer,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_buffer,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__mover__buffer_to_file,
        COMPILER__pfcnt__buffer__buffer_to_file,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_buffer,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_buffer,
        0,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__mover__buffer_copy__low_to_high,
        COMPILER__pfcnt__buffer__copy__low_to_high,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_buffer,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_buffer,
        0,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__mover__buffer_copy__high_to_low,
        COMPILER__pfcnt__buffer__copy__high_to_low,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_buffer,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_buffer,
        0,
    
    // file deleters
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__delete_file,
        COMPILER__pfcnt__buffer__delete_file,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_buffer,
        0,
    
    // list functions that dont require varying types
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__list__open_list,
        COMPILER__pfcnt__list__open,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_cell,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_list,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__list__close_list,
        COMPILER__pfcnt__list__close,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_list,
        0,
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__list__append__buffer_data,
        COMPILER__pfcnt__list__append__buffer_data,
        2,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_list,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_buffer,
        0,
    
    // time calls
    COMPILER__abt__define_function_call,
        COMPILER__ast__predefined__time__get_current_time,
        COMPILER__pfcnt__time__now,
        0,
        1,
        COMPILER__aat__COUNT + COMPILER__ptt__dragon_time,
    
    // end of blueprint
    COMPILER__abt__end_blueprint,
};

// cell ranges
typedef struct COMPILER__cell_range {
    ANVIL__cell_ID start;
    ANVIL__cell_ID end;
} COMPILER__cell_range;

// create custom cell range
COMPILER__cell_range COMPILER__create__cell_range(ANVIL__cell_ID start, ANVIL__cell_ID end) {
    COMPILER__cell_range output;

    // setup output
    output.start = start;
    output.end = end;

    return output;
}

// create null cell range
COMPILER__cell_range COMPILER__create_null__cell_range() {
    return COMPILER__create__cell_range(0, 0);
}

/* Blueprints */
// advance blueprintling by one
void COMPILER__next__blueprintling(ANVIL__current* current) {
    // next blueprintling
    (*current).start += sizeof(COMPILER__blueprintling);

    return;
}

// read one blueprintling but do not advance current
COMPILER__blueprintling COMPILER__read__blueprintling(ANVIL__current* current) {
    return *(COMPILER__blueprintling*)(*current).start;
}

// read one blueprintling and advance current to next one
COMPILER__blueprintling COMPILER__read_and_next__blueprintling(ANVIL__current* current) {
    COMPILER__blueprintling output;

    // read output
    output = COMPILER__read__blueprintling(current);

    // advance current
    COMPILER__next__blueprintling(current);

    return output;
}

/* Translation */
// calculate the amount of digits in a decimal number
ANVIL__length COMPILER__calculate__decimals_digit_count_in_number(ANVIL__u64 number) {
    ANVIL__length output = 0;

    // check for zero
    if (number == 0) {
        return 1;
    }

    // while there are digits left
    while (number > 0) {
        // divide by ten
        number /= 10;

        // increment digit count
        output++;
    }

    return output;
}

// create buffer string from number
ANVIL__buffer COMPILER__translate__integer_value_to_string(ANVIL__u64 number) {
    ANVIL__buffer output;
    ANVIL__length digit_count;

    // count digits
    digit_count = COMPILER__calculate__decimals_digit_count_in_number(number);

    // allocate output
    output = ANVIL__open__buffer(sizeof(ANVIL__character) * digit_count);

    // if allocation succeded
    if (ANVIL__check__empty_buffer(output) == ANVIL__bt__false) {
        // calculate characters
        for (ANVIL__u64 i = digit_count; i > 0; i--) {
            // create character
            ((ANVIL__character*)output.start)[i - 1] = '0' + (number % 10);

            // next character
            number /= 10;
        }
    }

    return output;
}

/* Character Locations */
// parsing character location
typedef struct COMPILER__character_location {
    ANVIL__file_index file_index;
    ANVIL__line_number line_number;
    ANVIL__character_index character_index;
} COMPILER__character_location;

// create custom character marker location
COMPILER__character_location COMPILER__create__character_location(ANVIL__file_index file_index, ANVIL__line_number line_number, ANVIL__character_index character_index) {
    COMPILER__character_location output;

    output.file_index = file_index;
    output.line_number = line_number;
    output.character_index = character_index;

    return output;
}

// create null character location
COMPILER__character_location COMPILER__create_null__character_location() {
    return COMPILER__create__character_location(-1, -1, -1);
}

/* Errors */
// error information
typedef struct COMPILER__error {
    ANVIL__bt occured;
    ANVIL__buffer message;
    COMPILER__character_location location;
    ANVIL__bt memory_error_occured;
} COMPILER__error;

// create custom error
COMPILER__error COMPILER__create__error(ANVIL__bt occured, ANVIL__buffer message, COMPILER__character_location location, ANVIL__bt memory_error_occured) {
    COMPILER__error output;

    // setup output
    output.occured = occured;
    output.message = message;
    output.location = location;
    output.memory_error_occured = memory_error_occured;

    return output;
}

// create null error
COMPILER__error COMPILER__create_null__error() {
    // return empty
    return COMPILER__create__error(ANVIL__bt__false, ANVIL__create_null__buffer(), COMPILER__create_null__character_location(), ANVIL__bt__false);
}

// open a specific error
COMPILER__error COMPILER__open__error(const char* message, COMPILER__character_location location) {
    return COMPILER__create__error(ANVIL__bt__true, ANVIL__open__buffer_from_string((u8*)message, ANVIL__bt__true, ANVIL__bt__false), location, ANVIL__bt__false);
}

// open a generic memory allocation error
COMPILER__error COMPILER__open__internal_memory_error() {
    return COMPILER__create__error(ANVIL__bt__true, ANVIL__open__buffer_from_string((u8*)"Internal memory error.", ANVIL__bt__true, ANVIL__bt__false), COMPILER__create_null__character_location(), ANVIL__bt__true);
}

// create an error report in json
ANVIL__buffer COMPILER__serialize__error_json(COMPILER__error error, ANVIL__bt* error_occured) {
    ANVIL__buffer output;
    ANVIL__list json;
    ANVIL__buffer temp_buffer;

    // initialize json string builder
    json = ANVIL__open__list(sizeof(ANVIL__character) * 2048, error_occured);

    // generate json
    ANVIL__list__append__buffer_data(&json, ANVIL__open__buffer_from_string((u8*)"\"error\": {\n\t\"message\": \"", ANVIL__bt__false, ANVIL__bt__false), error_occured);
    ANVIL__list__append__buffer_data(&json, error.message, error_occured);
    ANVIL__list__append__buffer_data(&json, ANVIL__open__buffer_from_string((u8*)"\",\n\t\"file_index\": \"", ANVIL__bt__false, ANVIL__bt__false), error_occured);
    temp_buffer = COMPILER__translate__integer_value_to_string(error.location.file_index);
    ANVIL__list__append__buffer_data(&json, temp_buffer, error_occured);
    ANVIL__close__buffer(temp_buffer);
    ANVIL__list__append__buffer_data(&json, ANVIL__open__buffer_from_string((u8*)"\",\n\t\"line_number\": \"", ANVIL__bt__false, ANVIL__bt__false), error_occured);
    temp_buffer = COMPILER__translate__integer_value_to_string(error.location.line_number);
    ANVIL__list__append__buffer_data(&json, temp_buffer, error_occured);
    ANVIL__close__buffer(temp_buffer);
    ANVIL__list__append__buffer_data(&json, ANVIL__open__buffer_from_string((u8*)"\",\n\t\"character_index\": \"", ANVIL__bt__false, ANVIL__bt__false), error_occured);
    temp_buffer = COMPILER__translate__integer_value_to_string(error.location.character_index);
    ANVIL__list__append__buffer_data(&json, temp_buffer, error_occured);
    ANVIL__close__buffer(temp_buffer);
    ANVIL__list__append__buffer_data(&json, ANVIL__open__buffer_from_string((u8*)"\"\n}\n", ANVIL__bt__false, ANVIL__bt__false), error_occured);

    // create buffer from list
    output = ANVIL__list__open_buffer_from_list(&json, error_occured);

    // clean up list
    ANVIL__close__list(json);

    return output;
}

// check to see if an error occured
ANVIL__bt COMPILER__check__error_occured(COMPILER__error* error) {
    // check for memory error
    if ((*error).memory_error_occured == ANVIL__bt__true) {
        // set error
        *error = COMPILER__open__internal_memory_error();
    }

    return (*error).occured;
}

// close an error
void COMPILER__close__error(COMPILER__error error) {
    // clean up buffers
    ANVIL__close__buffer(error.message);

    return;
}

/* List Functions With Errors */
// open a list but the error is a compiler error
ANVIL__list COMPILER__open__list_with_error(ANVIL__list_increase list_increase, COMPILER__error* error) {
    // open with error
    return ANVIL__open__list(list_increase, &((*error).memory_error_occured));
}

// append a buffer but the error is compiler
void COMPILER__append__buffer_with_error(ANVIL__list* list, ANVIL__buffer buffer, COMPILER__error* error) {
    ANVIL__list__append__buffer(list, buffer, &((*error).memory_error_occured));

    return;
}

// append structure index
void COMPILER__append__structure_index(ANVIL__list* list, COMPILER__structure_index data, COMPILER__error* error) {
    // request space
    ANVIL__list__request__space(list, sizeof(COMPILER__structure_index), &(*error).memory_error_occured);

    // append data
    (*(COMPILER__structure_index*)ANVIL__calculate__list_current_address(list)) = data;

    // increase fill
    (*list).filled_index += sizeof(COMPILER__structure_index);

    return;
}

// append function header index
void COMPILER__append__function_header_index(ANVIL__list* list, COMPILER__function_header_index data, COMPILER__error* error) {
    // request space
    ANVIL__list__request__space(list, sizeof(COMPILER__function_header_index), &(*error).memory_error_occured);

    // append data
    (*(COMPILER__function_header_index*)ANVIL__calculate__list_current_address(list)) = data;

    // increase fill
    (*list).filled_index += sizeof(COMPILER__function_header_index);

    return;
}

/* Counted List Functions With Errors */
ANVIL__counted_list COMPILER__open__counted_list_with_error(ANVIL__list_increase increase, COMPILER__error* error) {
    return ANVIL__create__counted_list(COMPILER__open__list_with_error(increase, error), 0);
}

/* Conversion */
// translate string to boolean
ANVIL__bt COMPILER__translate__string_to_boolean(ANVIL__buffer string, ANVIL__cell_integer_value* value) {
    // check possible values
    if (ANVIL__calculate__buffer_contents_equal(string, ANVIL__open__buffer_from_string((u8*)COMPILER__define__master_namespace ".boolean.false", ANVIL__bt__false, ANVIL__bt__false)) == ANVIL__bt__true) {
        *value = (ANVIL__cell_integer_value)(ANVIL__bt__false);

        return ANVIL__bt__true;
    }
    if (ANVIL__calculate__buffer_contents_equal(string, ANVIL__open__buffer_from_string((u8*)COMPILER__define__master_namespace ".boolean.true", ANVIL__bt__false, ANVIL__bt__false)) == ANVIL__bt__true) {
        *value = (ANVIL__cell_integer_value)(ANVIL__bt__true);

        return ANVIL__bt__true;
    }

    return ANVIL__bt__false;
}

// translate string to binary
ANVIL__bt COMPILER__translate__string_to_binary(ANVIL__buffer string, ANVIL__cell_integer_value* value) {
    ANVIL__buffer prefix = ANVIL__open__buffer_from_string((u8*)COMPILER__define__master_namespace ".binary.", ANVIL__bt__false, ANVIL__bt__false);
    ANVIL__buffer current;
    ANVIL__u64 character_count_limit = sizeof(ANVIL__u64) * ANVIL__define__bits_in_byte;
    ANVIL__u64 character_count = 0;

    // check for prefix
    if (ANVIL__calculate__buffer_starts_with_buffer(string, prefix) == ANVIL__bt__false) {
        // not a binary literal
        return ANVIL__bt__false;
    }

    // setup current
    current = ANVIL__create__buffer(string.start + ANVIL__calculate__buffer_length(prefix), string.end);

    // pre check for all valid characters
    while (ANVIL__check__current_within_range(current)) {
        // check character
        if ((ANVIL__check__character_range_at_current(current, '0', '1') || ANVIL__check__character_range_at_current(current, '_', '_')) == ANVIL__bt__false) {
            // not a binary literal
            return ANVIL__bt__false;
        }

        // count binary character
        if (ANVIL__check__character_range_at_current(current, '0', '1') == ANVIL__bt__true) {
            character_count++;
        }

        // advance current
        current.start += sizeof(ANVIL__character);
    }

    // check for same character limit
    if (character_count > character_count_limit) {
        // binary literal to large, conversion failed
        return ANVIL__bt__false;
    }

    // setup bit index
    ANVIL__bit_count bit_index = 0;

    // reset current
    current = ANVIL__create__buffer(string.start + ANVIL__calculate__buffer_length(prefix), string.end);

    // convert binary string to binary number
    while (ANVIL__check__current_within_range(current)) {
        if (ANVIL__check__character_range_at_current(current, '_', '_') == ANVIL__bt__false) {
            // append value
            *value += (((*(ANVIL__character*)current.start) - '0') << bit_index);

            // next bit index
            bit_index++;
        }

        // next character
        current.start += sizeof(ANVIL__character);
    }

    return ANVIL__bt__true;
}

// translate string to integer
ANVIL__bt COMPILER__translate__string_to_integer(ANVIL__buffer string, ANVIL__cell_integer_value* value) {
    ANVIL__buffer prefix = ANVIL__open__buffer_from_string((u8*)COMPILER__define__master_namespace ".integer.", ANVIL__bt__false, ANVIL__bt__false);
    ANVIL__buffer suffix;
    ANVIL__u64 digit = 0;

    // check for prefix
    if (ANVIL__calculate__buffer_starts_with_buffer(string, prefix) == ANVIL__bt__false) {
        // not an integer literal
        return ANVIL__bt__false;
    }

    // create suffix
    suffix = ANVIL__create__buffer(string.start + ANVIL__calculate__buffer_length(prefix), string.end);

    // translate number
    // if number is negative
    if (*(ANVIL__character*)suffix.start == (ANVIL__character)'n') {
        // for each character
        for (ANVIL__character_index i = ANVIL__calculate__buffer_length(suffix); i > 1; i--) {
            // check for valid character
            if (((((ANVIL__character*)suffix.start)[i - 1] >= '0' && ((ANVIL__character*)suffix.start)[i - 1] <= '9') || ((ANVIL__character*)suffix.start)[i - 1] == '_') == ANVIL__bt__false) {
                // invalid character
                return ANVIL__bt__false;
            }

            // if calculable character
            if (((ANVIL__character*)suffix.start)[i - 1] != '_') {
                // add value
                *value += ANVIL__calculate__exponent(10, digit) * (((ANVIL__character*)suffix.start)[i - 1] - '0');

                // next digit power
                digit++;
            }
        }

        // turn number negative using twos compliment
        *value = ~(*value);
        *value = (*value) + 1;
    // if number is positive
    } else {
        // for each character
        for (ANVIL__character_index i = ANVIL__calculate__buffer_length(suffix); i > 0; i--) {
            // check for valid character
            if (((((ANVIL__character*)suffix.start)[i - 1] >= '0' && ((ANVIL__character*)suffix.start)[i - 1] <= '9') || ((ANVIL__character*)suffix.start)[i - 1] == '_') == ANVIL__bt__false) {
                // invalid character
                return ANVIL__bt__false;
            }

            // if calculable character
            if (((ANVIL__character*)suffix.start)[i - 1] != '_') {
                // add value
                *value += ANVIL__calculate__exponent(10, digit) * (((ANVIL__character*)suffix.start)[i - 1] - '0');

                // next digit power
                digit++;
            }
        }
    }

    return ANVIL__bt__true;
}

// translate character to hexadecimal
ANVIL__cell_integer_value COMPILER__translate__character_to_hexadecimal(ANVIL__character character, ANVIL__bt* invalid_character) {
    // set character as valid
    *invalid_character = ANVIL__bt__false;

    // translate character
    if (character >= '0' && character <= '9') {
        return character - '0';
    } else if (character >= 'a' && character <= 'f') {
        return character - 'a' + 10;
    } else if (character >= 'A' && character <= 'F') {
        return character - 'A' + 10;
    } else {
        // invalid character
        *invalid_character = ANVIL__bt__true;
    }

    return ANVIL__define__null_address;
}

// translate string to hexedecimal
ANVIL__bt COMPILER__translate__string_to_hexadecimal(ANVIL__buffer string, ANVIL__cell_integer_value* value) {
    ANVIL__buffer prefix = ANVIL__open__buffer_from_string((u8*)COMPILER__define__master_namespace ".hexadecimal.", ANVIL__bt__false, ANVIL__bt__false);
    ANVIL__buffer suffix;
    ANVIL__buffer current;
    ANVIL__bt invalid_character;
    ANVIL__cell_integer_value hex_digit;

    // check for prefix
    if (ANVIL__calculate__buffer_starts_with_buffer(string, prefix) == ANVIL__bt__false) {
        // not a hexadecimal literal
        return ANVIL__bt__false;
    }

    // create suffix
    suffix = ANVIL__create__buffer(string.start + ANVIL__calculate__buffer_length(prefix), string.end);

    // create current
    current = suffix;

    // validate number
    while (ANVIL__check__current_within_range(current)) {
        // check separator
        if (*(ANVIL__character*)current.start == '_') {
            // skip
            current.start += sizeof(ANVIL__character);

            continue;
        }

        // check digit
        hex_digit = COMPILER__translate__character_to_hexadecimal(*(ANVIL__character*)current.start, &invalid_character);
        if (invalid_character == ANVIL__bt__true) {
            // invalid digit, invalid hex string
            return ANVIL__bt__false;
        }

        // next character
        current.start += sizeof(ANVIL__character);
    }

    // create current
    current = suffix;

    // translate number
    while (ANVIL__check__current_within_range(current)) {
        // check separator
        if (*(ANVIL__character*)current.start == '_') {
            // skip
            current.start += sizeof(ANVIL__character);

            continue;
        }

        // check digit
        hex_digit = COMPILER__translate__character_to_hexadecimal(*(ANVIL__character*)current.start, &invalid_character);

        // append digit
        *value = (*value) << 4;
        *value = (*value) & (~15);
        *value = (*value) + hex_digit;

        // next character
        current.start += sizeof(ANVIL__character);
    }

    return ANVIL__bt__true;
}

ANVIL__buffer COMPILER__convert__general_argument_type_to_string_buffer(COMPILER__pat argument_type) {
    return ANVIL__open__buffer_from_string((u8*)(COMPILER__global__general_argument_type_names[argument_type]), ANVIL__bt__false, ANVIL__bt__false);
}

#endif
