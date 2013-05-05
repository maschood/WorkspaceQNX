# This is an automatically generated record.
# The area between QNX Internal Start and QNX Internal End is controlled by
# the QNX IDE properties.

ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

USEFILE=

# Next lines are for C++ projects only

EXTRA_SUFFIXES+=cxx cpp

LDFLAGS+=-lang-c++

VFLAG_g=-gstabs+

LIBS+=ioaccess

<<<<<<< HEAD
#===== EXTRA_INCVPATH - a space-separated list of directories to search for include files.
EXTRA_INCVPATH+=$(PROJECT_ROOT)/Mutex $(PROJECT_ROOT)/HAL  \
	$(PROJECT_ROOT)/Versuchsordner $(PROJECT_ROOT)/HAL_A  \
	$(PROJECT_ROOT)/HAL_S $(PROJECT_ROOT)/HAWThread  \
	$(PROJECT_ROOT)/Hal_Test $(PROJECT_ROOT)/R232_1  \
	$(PROJECT_ROOT)/Regressionstest
=======
EXTRA_INCVPATH+=$(PROJECT_ROOT)/Mutex $(PROJECT_ROOT)/HAL
>>>>>>> Nilüfer

EXTRA_SRCVPATH+=$(PROJECT_ROOT)/HAL_Test  \
	$(PROJECT_ROOT)/R232_1 $(PROJECT_ROOT)/HAL_A  \
	$(PROJECT_ROOT)/HAL_S $(PROJECT_ROOT)/Regressionstest  \
	$(PROJECT_ROOT)/HAWThread $(PROJECT_ROOT)/Mutex  \
<<<<<<< HEAD
	$(PROJECT_ROOT)/Test_Empfaenger $(PROJECT_ROOT)/Test
=======
	$(PROJECT_ROOT)/Versuchsordner
>>>>>>> Erik

include $(MKFILES_ROOT)/qmacros.mk
ifndef QNX_INTERNAL
QNX_INTERNAL=$(PROJECT_ROOT)/.qnx_internal.mk
endif
include $(QNX_INTERNAL)

include $(MKFILES_ROOT)/qtargets.mk

OPTIMIZE_TYPE_g=none
OPTIMIZE_TYPE=$(OPTIMIZE_TYPE_$(filter g, $(VARIANTS)))

