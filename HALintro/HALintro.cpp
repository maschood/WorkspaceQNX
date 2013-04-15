/*
 * HALintro.cpp
 */

#include "HALintro.h"
#include "HWaccess.h"
#include "Addresses.h"

#include <stdint.h>

HALintro* HALintro::instance = NULL;

HALintro::HALintro() {
    // Initialisierung der Digitalen IO Karte
    out8(DIO_BASE + DIO_OFFS_CTRL, 0x8A);
    out8(DIO_BASE + DIO_OFFS_A, 0x00);
    out8(DIO_BASE + DIO_OFFS_C, 0x00);
}

HALintro::~HALintro() {
    delete instance;
    instance = NULL;
}

HALintro* HALintro::getInstance()
{
    // Zugriffsrechte fuer den Zugriff auf die HW holen
    if (-1 == ThreadCtl(_NTO_TCTL_IO, 0)) {
        perror("ThreadCtl access failed\n");
        return NULL;
    }

    if (instance == NULL) {
        instance = new HALintro();
    }
    return instance;

}

void HALintro::lampeRotAn()
{
    uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
    out8(DIO_BASE + DIO_OFFS_A, val | BIT_7);
}

void HALintro::lampeRotAus()
{
    uint8_t val = in8(DIO_BASE + DIO_OFFS_A);
    out8(DIO_BASE + DIO_OFFS_A, val & ~BIT_7);
}
