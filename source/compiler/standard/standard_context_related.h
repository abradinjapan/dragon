#ifndef DRAGON__compiler__generator__context_related
#define DRAGON__compiler__generator__context_related

/* Include */
#include "standard_specifications.h"

/* Functions */
// register types
typedef enum STANDARD__set_inputs_in_context_buffer {
	// preserve start
	STANDARD__set_inputs_in_context_buffer__preserve__START = ANVIL__srt__start__workspace,

	// variables
	STANDARD__set_inputs_in_context_buffer__context_start = STANDARD__set_inputs_in_context_buffer__preserve__START,
	STANDARD__set_inputs_in_context_buffer__context_end,
	STANDARD__set_inputs_in_context_buffer__input_start,
	STANDARD__set_inputs_in_context_buffer__input_end,
	STANDARD__set_inputs_in_context_buffer__input_start_offset,
    STANDARD__set_inputs_in_context_buffer__input_end_offset,
	STANDARD__set_inputs_in_context_buffer__input_start_address,
	STANDARD__set_inputs_in_context_buffer__input_end_address,

	// preserve end
	STANDARD__set_inputs_in_context_buffer__preserve__END,

	// inputs
	STANDARD__set_inputs_in_context_buffer__input__context_start = ANVIL__srt__start__function_io,
	STANDARD__set_inputs_in_context_buffer__input__context_end,
	STANDARD__set_inputs_in_context_buffer__input__input_start,
	STANDARD__set_inputs_in_context_buffer__input__input_end,
} STANDARD__set_inputs_in_context_buffer;

// call function
void STANDARD__code__call__set_inputs_in_context_buffer(ANVIL__workspace* workspace, STANDARD__offsets* anvil_offsets, ANVIL__flag_ID flag, ANVIL__cell_ID input__context_start, ANVIL__cell_ID input__context_end, ANVIL__cell_ID input__input_start, ANVIL__cell_ID input__input_end) {
	// pass inputs
	ANVIL__code__cell_to_cell(workspace, flag, input__context_start, STANDARD__set_inputs_in_context_buffer__input__context_start);
	ANVIL__code__cell_to_cell(workspace, flag, input__context_end, STANDARD__set_inputs_in_context_buffer__input__context_end);
	ANVIL__code__cell_to_cell(workspace, flag, input__input_start, STANDARD__set_inputs_in_context_buffer__input__input_start);
	ANVIL__code__cell_to_cell(workspace, flag, input__input_end, STANDARD__set_inputs_in_context_buffer__input__input_end);

	// call function
	ANVIL__code__call__static(workspace, flag, (*anvil_offsets).offsets[STANDARD__sot__set_inputs_in_context_buffer__start]);

	return;
}

// build function
void STANDARD__code__set_inputs_in_context_buffer(ANVIL__workspace* workspace, STANDARD__offsets* anvil_offsets) {
	// setup function offset
	(*anvil_offsets).offsets[STANDARD__sot__set_inputs_in_context_buffer__start] = ANVIL__get__offset(workspace);

	// setup function prologue
	ANVIL__code__preserve_workspace(workspace, ANVIL__sft__always_run, STANDARD__set_inputs_in_context_buffer__preserve__START, STANDARD__set_inputs_in_context_buffer__preserve__END);

	// get inputs
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__set_inputs_in_context_buffer__input__context_start, STANDARD__set_inputs_in_context_buffer__context_start);
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__set_inputs_in_context_buffer__input__context_end, STANDARD__set_inputs_in_context_buffer__context_end);
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__set_inputs_in_context_buffer__input__input_start, STANDARD__set_inputs_in_context_buffer__input_start);
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__set_inputs_in_context_buffer__input__input_end, STANDARD__set_inputs_in_context_buffer__input_end);

	// calculate variable addresses
    ANVIL__code__write_cell(workspace, (ANVIL__cell)(ANVIL__srt__input_buffer_start * sizeof(ANVIL__cell)), STANDARD__set_inputs_in_context_buffer__input_start_offset);
    ANVIL__code__write_cell(workspace, (ANVIL__cell)(ANVIL__srt__input_buffer_end * sizeof(ANVIL__cell)), STANDARD__set_inputs_in_context_buffer__input_end_offset);
    ANVIL__code__operate(workspace, ANVIL__sft__always_run, ANVIL__ot__integer_add, STANDARD__set_inputs_in_context_buffer__context_start, STANDARD__set_inputs_in_context_buffer__input_start_offset, ANVIL__unused_cell_ID, STANDARD__set_inputs_in_context_buffer__input_start_address);
    ANVIL__code__operate(workspace, ANVIL__sft__always_run, ANVIL__ot__integer_add, STANDARD__set_inputs_in_context_buffer__context_start, STANDARD__set_inputs_in_context_buffer__input_end_offset, ANVIL__unused_cell_ID, STANDARD__set_inputs_in_context_buffer__input_end_address);

    // write data
    ANVIL__code__cell_to_address(workspace, ANVIL__sft__always_run, STANDARD__set_inputs_in_context_buffer__input_start, ANVIL__srt__constant__cell_byte_size, STANDARD__set_inputs_in_context_buffer__input_start_address);
    ANVIL__code__cell_to_address(workspace, ANVIL__sft__always_run, STANDARD__set_inputs_in_context_buffer__input_end, ANVIL__srt__constant__cell_byte_size, STANDARD__set_inputs_in_context_buffer__input_end_address);

	// setup function epilogue
	ANVIL__code__restore_workspace(workspace, ANVIL__sft__always_run, STANDARD__set_inputs_in_context_buffer__preserve__START, STANDARD__set_inputs_in_context_buffer__preserve__END);

	// return to caller
	ANVIL__code__jump__explicit(workspace, ANVIL__sft__always_run, ANVIL__srt__return_address);

	return;
}

// register types
typedef enum STANDARD__get_outputs_from_context_buffer {
	// preserve start
	STANDARD__get_outputs_from_context_buffer__preserve__START = ANVIL__srt__start__workspace,

	// variables
	STANDARD__get_outputs_from_context_buffer__context_start = STANDARD__get_outputs_from_context_buffer__preserve__START,
	STANDARD__get_outputs_from_context_buffer__context_end,
	STANDARD__get_outputs_from_context_buffer__output_start,
	STANDARD__get_outputs_from_context_buffer__output_end,
	STANDARD__get_outputs_from_context_buffer__output_start_read_offset,
	STANDARD__get_outputs_from_context_buffer__output_end_read_offset,
	STANDARD__get_outputs_from_context_buffer__output_start_read_address,
	STANDARD__get_outputs_from_context_buffer__output_end_read_address,

	// preserve end
	STANDARD__get_outputs_from_context_buffer__preserve__END,

	// inputs
	STANDARD__get_outputs_from_context_buffer__input__context_start = ANVIL__srt__start__function_io,
	STANDARD__get_outputs_from_context_buffer__input__context_end,

	// outputs
	STANDARD__get_outputs_from_context_buffer__output__output_start = ANVIL__srt__start__function_io,
	STANDARD__get_outputs_from_context_buffer__output__output_end,
} STANDARD__get_outputs_from_context_buffer;

// call function
void STANDARD__code__call__get_outputs_from_context_buffer(ANVIL__workspace* workspace, STANDARD__offsets* anvil_offsets, ANVIL__flag_ID flag, ANVIL__cell_ID input__context_start, ANVIL__cell_ID input__context_end, ANVIL__cell_ID output__output_start, ANVIL__cell_ID output__output_end) {
	// pass inputs
	ANVIL__code__cell_to_cell(workspace, flag, input__context_start, STANDARD__get_outputs_from_context_buffer__input__context_start);
	ANVIL__code__cell_to_cell(workspace, flag, input__context_end, STANDARD__get_outputs_from_context_buffer__input__context_end);

	// call function
	ANVIL__code__call__static(workspace, flag, (*anvil_offsets).offsets[STANDARD__sot__get_outputs_from_context_buffer__start]);

	// pass outputs
	ANVIL__code__cell_to_cell(workspace, flag, STANDARD__get_outputs_from_context_buffer__output__output_start, output__output_start);
	ANVIL__code__cell_to_cell(workspace, flag, STANDARD__get_outputs_from_context_buffer__output__output_end, output__output_end);

	return;
}

// build function
void STANDARD__code__get_outputs_from_context_buffer(ANVIL__workspace* workspace, STANDARD__offsets* anvil_offsets) {
	// setup function offset
	(*anvil_offsets).offsets[STANDARD__sot__get_outputs_from_context_buffer__start] = ANVIL__get__offset(workspace);

	// setup function prologue
	ANVIL__code__preserve_workspace(workspace, ANVIL__sft__always_run, STANDARD__get_outputs_from_context_buffer__preserve__START, STANDARD__get_outputs_from_context_buffer__preserve__END);

	// get inputs
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__get_outputs_from_context_buffer__input__context_start, STANDARD__get_outputs_from_context_buffer__context_start);
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__get_outputs_from_context_buffer__input__context_end, STANDARD__get_outputs_from_context_buffer__context_end);

	// setup addresses
    ANVIL__code__write_cell(workspace, (ANVIL__cell)(ANVIL__srt__output_buffer_start * sizeof(ANVIL__cell)), STANDARD__get_outputs_from_context_buffer__output_start_read_offset);
    ANVIL__code__write_cell(workspace, (ANVIL__cell)(ANVIL__srt__output_buffer_end * sizeof(ANVIL__cell)), STANDARD__get_outputs_from_context_buffer__output_end_read_offset);
    ANVIL__code__operate(workspace, ANVIL__sft__always_run, ANVIL__ot__integer_add, STANDARD__get_outputs_from_context_buffer__context_start, STANDARD__get_outputs_from_context_buffer__output_start_read_offset, ANVIL__unused_cell_ID, STANDARD__get_outputs_from_context_buffer__output_start_read_address);
    ANVIL__code__operate(workspace, ANVIL__sft__always_run, ANVIL__ot__integer_add, STANDARD__get_outputs_from_context_buffer__context_start, STANDARD__get_outputs_from_context_buffer__output_end_read_offset, ANVIL__unused_cell_ID, STANDARD__get_outputs_from_context_buffer__output_end_read_address);

    // perform reads
    ANVIL__code__address_to_cell(workspace, ANVIL__sft__always_run, STANDARD__get_outputs_from_context_buffer__output_start_read_address, ANVIL__srt__constant__cell_byte_size, STANDARD__get_outputs_from_context_buffer__output_start);
    ANVIL__code__address_to_cell(workspace, ANVIL__sft__always_run, STANDARD__get_outputs_from_context_buffer__output_end_read_address, ANVIL__srt__constant__cell_byte_size, STANDARD__get_outputs_from_context_buffer__output_end);

	// setup outputs
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__get_outputs_from_context_buffer__output_start, STANDARD__get_outputs_from_context_buffer__output__output_start);
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__get_outputs_from_context_buffer__output_end, STANDARD__get_outputs_from_context_buffer__output__output_end);

	// setup function epilogue
	ANVIL__code__restore_workspace(workspace, ANVIL__sft__always_run, STANDARD__get_outputs_from_context_buffer__preserve__START, STANDARD__get_outputs_from_context_buffer__preserve__END);

	// return to caller
	ANVIL__code__jump__explicit(workspace, ANVIL__sft__always_run, ANVIL__srt__return_address);

	return;
}

#endif
