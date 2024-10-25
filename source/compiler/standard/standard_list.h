#ifndef DRAGON__compiler__standard__list
#define DRAGON__compiler__standard__list

/* Include */
#include "standard_specifications.h"

/* List */
// cell types
typedef enum STANDARD__open_list {
	// preserve start
	STANDARD__open_list__preserve__START = ANVIL__srt__start__workspace,

	// variables
	STANDARD__open_list__list_allocation_start = STANDARD__open_list__preserve__START,
	STANDARD__open_list__list_allocation_end,
	STANDARD__open_list__list_content_start,
	STANDARD__open_list__list_content_end,
	STANDARD__open_list__list_increase,

	// preserve end
	STANDARD__open_list__preserve__END,

	// inputs
	STANDARD__open_list__input__increase = ANVIL__srt__start__function_io,

	// outputs
	STANDARD__open_list__output__list_allocation_start = ANVIL__srt__start__function_io,
	STANDARD__open_list__output__list_allocation_end,
	STANDARD__open_list__output__list_content_start,
	STANDARD__open_list__output__list_content_end,
	STANDARD__open_list__output__list_increase,
} STANDARD__open_list;

// call function
void STANDARD__code__call__open_list(ANVIL__workspace* workspace, STANDARD__offsets* standard_offsets, ANVIL__flag_ID flag, ANVIL__cell_ID input__increase, ANVIL__cell_ID output__list_allocation_start, ANVIL__cell_ID output__list_allocation_end, ANVIL__cell_ID output__list_content_start, ANVIL__cell_ID output__list_content_end, ANVIL__cell_ID output__list_increase) {
	// pass inputs
	ANVIL__code__cell_to_cell(workspace, flag, input__increase, STANDARD__open_list__input__increase);

	// call function
	ANVIL__code__call__static(workspace, flag, (*standard_offsets).offsets[STANDARD__ot__open_list__start]);

	// pass outputs
	ANVIL__code__cell_to_cell(workspace, flag, STANDARD__open_list__output__list_allocation_start, output__list_allocation_start);
	ANVIL__code__cell_to_cell(workspace, flag, STANDARD__open_list__output__list_allocation_end, output__list_allocation_end);
	ANVIL__code__cell_to_cell(workspace, flag, STANDARD__open_list__output__list_content_start, output__list_content_start);
	ANVIL__code__cell_to_cell(workspace, flag, STANDARD__open_list__output__list_content_end, output__list_content_end);
	ANVIL__code__cell_to_cell(workspace, flag, STANDARD__open_list__output__list_increase, output__list_increase);

	return;
}

// build function
void STANDARD__code__open_list(ANVIL__workspace* workspace, STANDARD__offsets* standard_offsets) {
	// setup function offset
	(*standard_offsets).offsets[STANDARD__ot__open_list__start] = ANVIL__get__offset(workspace);

	// setup function prologue
	ANVIL__code__preserve_workspace(workspace, ANVIL__sft__always_run, STANDARD__open_list__preserve__START, STANDARD__open_list__preserve__END);

	// get inputs
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__open_list__input__increase, STANDARD__open_list__list_increase);

	// open list
    ANVIL__code__request_memory(workspace, STANDARD__open_list__list_increase, STANDARD__open_list__list_allocation_start, STANDARD__open_list__list_allocation_end);
    ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__open_list__list_allocation_start, STANDARD__open_list__list_content_start);
	ANVIL__code__operate(workspace, ANVIL__sft__always_run, ANVIL__ot__integer_subtract, STANDARD__open_list__list_content_start, ANVIL__srt__constant__1, ANVIL__unused_cell_ID, STANDARD__open_list__list_content_end);

	// setup outputs
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__open_list__list_allocation_start, STANDARD__open_list__output__list_allocation_start);
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__open_list__list_allocation_end, STANDARD__open_list__output__list_allocation_end);
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__open_list__list_content_start, STANDARD__open_list__output__list_content_start);
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__open_list__list_content_end, STANDARD__open_list__output__list_content_end);
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__open_list__list_increase, STANDARD__open_list__output__list_increase);

	// setup function epilogue
	ANVIL__code__restore_workspace(workspace, ANVIL__sft__always_run, STANDARD__open_list__preserve__START, STANDARD__open_list__preserve__END);

	// return to caller
	ANVIL__code__jump__explicit(workspace, ANVIL__sft__always_run, ANVIL__srt__return_address);

	return;
}

// cell types
typedef enum STANDARD__close_list {
	// preserve start
	STANDARD__close_list__preserve__START = ANVIL__srt__start__workspace,

	// variables
	STANDARD__close_list__list_allocation_start = STANDARD__close_list__preserve__START,
	STANDARD__close_list__list_allocation_end,
	STANDARD__close_list__list_content_start,
	STANDARD__close_list__list_content_end,
	STANDARD__close_list__list_increase,

	// preserve end
	STANDARD__close_list__preserve__END,

	// inputs
	STANDARD__close_list__input__list_allocation_start = ANVIL__srt__start__function_io,
	STANDARD__close_list__input__list_allocation_end,
	STANDARD__close_list__input__list_increase,
	STANDARD__close_list__input__list_content_start,
	STANDARD__close_list__input__list_content_end,

	// outputs
} STANDARD__close_list;

// call function
void STANDARD__code__call__close_list(ANVIL__workspace* workspace, STANDARD__offsets* standard_offsets, ANVIL__flag_ID flag, ANVIL__cell_ID input__list_allocation_start, ANVIL__cell_ID input__list_allocation_end, ANVIL__cell_ID input__list_content_start, ANVIL__cell_ID input__list_content_end, ANVIL__cell_ID input__list_increase) {
	// pass inputs
	ANVIL__code__cell_to_cell(workspace, flag, input__list_allocation_start, STANDARD__close_list__input__list_allocation_start);
	ANVIL__code__cell_to_cell(workspace, flag, input__list_allocation_end, STANDARD__close_list__input__list_allocation_end);
	ANVIL__code__cell_to_cell(workspace, flag, input__list_content_start, STANDARD__close_list__input__list_content_start);
	ANVIL__code__cell_to_cell(workspace, flag, input__list_content_end, STANDARD__close_list__input__list_content_end);
	ANVIL__code__cell_to_cell(workspace, flag, input__list_increase, STANDARD__close_list__input__list_increase);

	// call function
	ANVIL__code__call__static(workspace, flag, (*standard_offsets).offsets[STANDARD__ot__close_list__start]);

	return;
}

// build function
void STANDARD__code__close_list(ANVIL__workspace* workspace, STANDARD__offsets* standard_offsets) {
	// setup function offset
	(*standard_offsets).offsets[STANDARD__ot__close_list__start] = ANVIL__get__offset(workspace);

	// setup function prologue
	ANVIL__code__preserve_workspace(workspace, ANVIL__sft__always_run, STANDARD__close_list__preserve__START, STANDARD__close_list__preserve__END);

	// get inputs
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__close_list__input__list_allocation_start, STANDARD__close_list__list_allocation_start);
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__close_list__input__list_allocation_end, STANDARD__close_list__list_allocation_end);
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__close_list__input__list_content_start, STANDARD__close_list__list_content_start);
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__close_list__input__list_content_end, STANDARD__close_list__list_content_end);
	ANVIL__code__cell_to_cell(workspace, ANVIL__sft__always_run, STANDARD__close_list__input__list_increase, STANDARD__close_list__list_increase);

	// close buffer
	ANVIL__code__return_memory(workspace, STANDARD__close_list__list_allocation_start, STANDARD__close_list__list_allocation_end);

	// setup function epilogue
	ANVIL__code__restore_workspace(workspace, ANVIL__sft__always_run, STANDARD__close_list__preserve__START, STANDARD__close_list__preserve__END);

	// return to caller
	ANVIL__code__jump__explicit(workspace, ANVIL__sft__always_run, ANVIL__srt__return_address);

	return;
}

#endif