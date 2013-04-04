#ifdef __cplusplus
extern "C" {
#endif

#ifndef WRAPPERS_H_
#define WRAPPERS_H_

#include <stdint.h>
#include <sys/neutrino.h>
#include <hw/inout.h>

/**
 * InterruptAttach
 */
int MyInterruptAttach(int intr,
		const struct sigevent * (* handler)(void *, int),
		const void * area,
		int size,
		unsigned flags );
int OrgInterruptAttach(int intr,
		const struct sigevent *(* handler)(void *, int),
		const void *area,
		int size,
		unsigned flags);
#define InterruptAttach MyInterruptAttach


/**
 * InterruptAttachEvent
 */
int MyInterruptAttachEvent(int intr,
		const struct sigevent *event, unsigned flags);
int OrgInterruptAttachEvent(int intr,
		const struct sigevent *event, unsigned flags);
#define InterruptAttachEvent MyInterruptAttachEvent


/**
 * InterruptDetach
 */
int MyInterruptDetach(int id);
int OrgInterruptDetach(int id);
#define InterruptDetach MyInterruptDetach


/**
 * InterruptMask
 */
int MyInterruptMask(int intr, int id);
int OrgInterruptMask(int intr, int id);
#define InterruptMask MyInterruptMask


/**
 * InterruptUnmask
 */
int MyInterruptUnmask(int intr, int id);
int OrgInterruptUnmask(int intr, int id);
#define InterruptUnmask MyInterruptUnmask


/**
 * InterruptWait
 */
int MyInterruptWait(int flags, const uint64_t *timeout);
int OrgInterruptWait(int flags, const uint64_t *timeout);
#define InterruptWait MyInterruptWait


/**
 * out8
 */
void MyOut8(uintptr_t port, uint8_t val);
void OrgOut8(uintptr_t port, uint8_t val);
#define out8 MyOut8


/**
 * in8
 */
uint8_t MyIn8(uintptr_t port);
uint8_t OrgIn8(uintptr_t port);
#define in8 MyIn8

#endif /* WRAPPERS_H_ */

#ifdef __cplusplus
}
#endif

