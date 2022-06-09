#pragma once

#include <cstdint>
#include <string>

/**
 * \mainpage Medica Sofware Definion
 * - \subpage pageMessage
 * - \subpage pageUi
 * \defgroup core Core Definitionen
 *
 *
 */

/**
 *  \ingroup core
 *  @{
 */


using TInt16 = int16_t;     ///< Definition für einen Vorzeichenbehafteten 16 Bit Wert
using TUint32 = uint32_t;   ///< Definition für einen Vorzeichenlosen 32 Bit Wert
using TInt32 = int32_t;     ///< Definition für einen Vorzeichenbehafteten 32 Bit Wert
using TFloat = float;       ///< Definition für einen Float (32 bit)
using TDouble = double;     ///< Definition für einen Doppelten Float (64 bit)

using TUtf8 = std::string;   ///< Ein String der als UTF8 Interpretiert wird

using TNewton = TFloat;      ///< Einheit für Kräfte
using TNewtonMeter = TFloat; ///< Drehmoment in Newton
using TRpm = TFloat;         /**<
                             * Einheit für Umdrehungen.
                             * - Positiver Wert ist Vorwärts
                             * - Negativer Wert Rückwärts
                             */
using TWatt = TFloat;        /**<
                             * Einheit für Arbeit.
                             */
using TSymmetry = TFloat;    /**<
                             * Durchschnittliche Krafteinsatz der beiden Seiten in Prozent
                             * < 50 % mehr Kraft auf der Linken Seite
                             * > 50 % mehr Kraft auf der Rechten Seite
                             * Bereich von 0. bis 100.
                             */
using TAngle = TFloat;      /**<
                             * Einheit für den Winkel.
                             * Bereich von 0. bis 360.
                             */


/** @} */
