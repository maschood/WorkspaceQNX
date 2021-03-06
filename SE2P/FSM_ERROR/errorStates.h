/**
 * @file errorStates.h
 * @author Erik Matthiessen
 *         Denis Rycka
 *         Nil�fer G�ng�r
 *         Maschhood Ahmad
 */

#ifndef ERRORSTATES_H_
#define ERRORSTATES_H_

enum state {
	ERR_STATE_IDLE,
	ERR_STATE_SLIDE_FULL,
	ERR_STATE_SLIDE_FULL_RECEIPTED,
	ERR_STATE_TURNOVER,
	ERR_STATE_ERROR,
	ERR_STATE_ERROR_RECEIPTED,
	ERR_STATE_ERROR_MIN,
	ERR_STATE_ERROR_RECEIPTED_MIN,
	ERR_STATE_ERROR_MAX,
	ERR_STATE_ERROR_RECEIPTED_MAX,
	ERR_STATE_TURNOVER_BAND2,
	ERR_STATE_TURNOVER_BAND2_RECEIPTED,
	ERR_STATE_METAL_TURNOVER_BAND2,
	ERR_STATE_METAL_TURNOVER_BAND2_RECEIPTED,
	ERR_STATE_ESTOP,
	ERR_STATE_ESTOP_RECEIPTED,
	ERR_STATE_STOP,
};

#endif /* ERRORSTATES_H_ */
