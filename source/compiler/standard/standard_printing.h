#ifndef DRAGON__compiler__generator__printing
#define DRAGON__compiler__generator__printing

/* Include */
#include "standard_specifications.h"

/* Functions */
// cell types
typedef enum STANDARD__calculate_decimal_digit_count {
	// preserve start
	STANDARD__calculate_decimal_digit_count__preserve__START = ANVIL__srt__start__workspace,

	// variables
	STANDARD__calculate_decimal_digit_count__value = STANDARD__calculate_decimal_digit_count__preserve__START,
	STANDARD__calculate_decimal_digit_count__digit_count,
	STANDARD__calculate_decimal_digit_count__zero,
	STANDARD__calculate_decimal_digit_count__ten,

	// preserve end
	STANDARD__calculate_decimal_digit_count__preserve__END,

	// inputs
	STANDARD__calculate_decimal_digit_count__input__value = ANVIL__srt__start__function_io,

	// outputs
	STANDARD__calculate_decimal_digit_count__output__digit_count = ANVIL__srt__start__function_io,
} STANDARD__calculate_decimal_digit_count;

// call function
void STANDARD__code__call__calculate_decimal_digit_count(ANVIL__workspace* workspace, STANDARD__offsets* std_offsets, ANVIL__flag_ID flag, ANVIL__cell_ID input__value, ANVIL__cell_ID output__digit_count) {
	// pass inputs
	ANVIL__code__cell_to_cell(workspace, flag, input__value, STANDARD__calculate_decimal_digit_count__input__value);

	// call function
	ANVIL__code__call__static(workspace, flag, (*std_offsets).offsets[STANDARD__sot__calculate_decimal_digit_count__start]);

	// pass outputs
	ANVIL__code__cell_to_cell(workspace, flag, STANDARD__calculate_decimal_digit_count__output__digit_count, output__digit_count);

	return;
}

// build function
void STANDARD__code__calculate_decimal_digit_count(ANVIL__workspace* workspace, STANDARD__offsets* std_offsets) {
	// setup function offset
	(*std_offsets).offsets[STANDARD__sot__calculate_decimal_digit_count__start] = ANVIL__get__offset(workspace);

	// setup function prologue
	ANVIL__code__preserve_workspace(workspace, ANVIL__sft__always_run, STANDARD__calculate_decimal_digit_count__preserve__START, STANDARD__calculate_decimal_digit_count__preserve__END);

	// get inputs
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__calculate_decimal_digit_count__input__value, STANDARD__calculate_decimal_digit_count__value);

    // check for zero
    ANVIL__code__write_cell(workspace, (ANVIL__cell)0, STANDARD__calculate_decimal_digit_count__zero);
    ANVIL__code__write_cell(workspace, (ANVIL__cell)1, STANDARD__calculate_decimal_digit_count__digit_count);
    ANVIL__code__operate__jump__static(workspace, ANVIL__sft__always_run, STANDARD__calculate_decimal_digit_count__zero, STANDARD__calculate_decimal_digit_count__value, STANDARD__calculate_decimal_digit_count__zero, ANVIL__sft__never_run, (*std_offsets).offsets[STANDARD__sot__calculate_decimal_digit_count__return]);

    // not a zero, set to default
    ANVIL__code__write_cell(workspace, (ANVIL__cell)0, STANDARD__calculate_decimal_digit_count__digit_count);

    // setup remaining variables
    ANVIL__code__write_cell(workspace, (ANVIL__cell)10, STANDARD__calculate_decimal_digit_count__ten);

	// setup loop start
	(*std_offsets).offsets[STANDARD__sot__calculate_decimal_digit_count__loop_start] = ANVIL__get__offset(workspace);

    // check for remaining digits
    ANVIL__code__operate__jump__static(workspace, ANVIL__sft__always_run, STANDARD__calculate_decimal_digit_count__zero, STANDARD__calculate_decimal_digit_count__value, STANDARD__calculate_decimal_digit_count__zero, ANVIL__sft__never_run, (*std_offsets).offsets[STANDARD__sot__calculate_decimal_digit_count__return]);

    // perform divide
    ANVIL__code__operate(workspace, ANVIL__sft__always_run, ANVIL__ot__integer_division, STANDARD__calculate_decimal_digit_count__value, STANDARD__calculate_decimal_digit_count__ten, ANVIL__unused_cell_ID, STANDARD__calculate_decimal_digit_count__value);

    // increment count
    ANVIL__code__operate(workspace, ANVIL__sft__always_run, ANVIL__ot__integer_add, STANDARD__calculate_decimal_digit_count__digit_count, ANVIL__srt__constant__1, ANVIL__unused_cell_ID, STANDARD__calculate_decimal_digit_count__digit_count);

    // jump to beginning
    ANVIL__code__jump__static(workspace, ANVIL__sft__always_run, (*std_offsets).offsets[STANDARD__sot__calculate_decimal_digit_count__loop_start]);

	// setup loop return
	(*std_offsets).offsets[STANDARD__sot__calculate_decimal_digit_count__return] = ANVIL__get__offset(workspace);

	// setup outputs
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__calculate_decimal_digit_count__digit_count, STANDARD__calculate_decimal_digit_count__output__digit_count);

	// setup function epilogue
	ANVIL__code__restore_workspace(workspace, ANVIL__sft__always_run, STANDARD__calculate_decimal_digit_count__preserve__START, STANDARD__calculate_decimal_digit_count__preserve__END);

	// return to caller
	ANVIL__code__jump__explicit(workspace, ANVIL__sft__always_run, ANVIL__srt__return_address);

	return;
}

// cell types
typedef enum STANDARD__print_binary {
	// preserve start
	STANDARD__print_binary__preserve__START = ANVIL__srt__start__workspace,

	// variables
	STANDARD__print_binary__value = STANDARD__print_binary__preserve__START,
    STANDARD__print_binary__bit,
    STANDARD__print_binary__character,

	// preserve end
	STANDARD__print_binary__preserve__END,

	// inputs
	STANDARD__print_binary__input__value = ANVIL__srt__start__function_io,

	// outputs
} STANDARD__print_binary;

// call function
void STANDARD__code__call__print_binary(ANVIL__workspace* workspace, STANDARD__offsets* standard_offsets, ANVIL__flag_ID flag, ANVIL__cell_ID input__value) {
	// pass inputs
	ANVIL__code__cell_to_cell(workspace, flag, input__value, STANDARD__print_binary__input__value);

	// call function
	ANVIL__code__call__static(workspace, flag, (*standard_offsets).offsets[STANDARD__sot__print_binary__start]);

	return;
}

// build function
void STANDARD__code__print_binary(ANVIL__workspace* workspace, STANDARD__offsets* standard_offsets) {
	// setup function offset
	(*standard_offsets).offsets[STANDARD__sot__print_binary__start] = ANVIL__get__offset(workspace);

	// setup function prologue
	ANVIL__code__preserve_workspace(workspace, ANVIL__sft__always_run, STANDARD__print_binary__preserve__START, STANDARD__print_binary__preserve__END);

	// get inputs
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__print_binary__input__value, STANDARD__print_binary__value);

	// print all bits
    // for each byte
    for (ANVIL__byte_count byte_index = 0; byte_index < sizeof(ANVIL__cell); byte_index++) {
        // for each bit
        for (ANVIL__bit_count bit_index = 0; bit_index < ANVIL__define__bits_in_byte; bit_index++) {
            // get bit
            ANVIL__code__operate(workspace, ANVIL__sft__always_run, ANVIL__ot__bits_and, STANDARD__print_binary__value, ANVIL__srt__constant__1, ANVIL__unused_cell_ID, STANDARD__print_binary__bit);

            // get character
            ANVIL__code__write_cell(workspace, (ANVIL__cell)'0', STANDARD__print_binary__character);
            ANVIL__code__operate(workspace, ANVIL__sft__always_run, ANVIL__ot__integer_add, STANDARD__print_binary__character, STANDARD__print_binary__bit, ANVIL__unused_cell_ID, STANDARD__print_binary__character);

            // print character
            ANVIL__code__debug__putchar(workspace, STANDARD__print_binary__character);

            // next bit
            ANVIL__code__operate(workspace, ANVIL__sft__always_run, ANVIL__ot__bits_shift_lower, STANDARD__print_binary__value, ANVIL__srt__constant__1, ANVIL__unused_cell_ID, STANDARD__print_binary__value);
        }

        // print separator if not end of loop
        if (byte_index < sizeof(ANVIL__cell) - 1) {
            ANVIL__code__write_cell(workspace, (ANVIL__cell)'_', STANDARD__print_binary__character);
            ANVIL__code__debug__putchar(workspace, STANDARD__print_binary__character);
        }
    }

	// setup function epilogue
	ANVIL__code__restore_workspace(workspace, ANVIL__sft__always_run, STANDARD__print_binary__preserve__START, STANDARD__print_binary__preserve__END);

	// return to caller
	ANVIL__code__jump__explicit(workspace, ANVIL__sft__always_run, ANVIL__srt__return_address);

	return;
}

#endif
