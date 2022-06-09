#pragma once 

#include "../def.h"


namespace message {

/**
 * Definiert die Möglichen Tasten Typen der Hardware.
 * \ingroup message
 */
enum class EHwKeyType : TUint32 {
    Start,          /**<
                     * Start Taste. Ist gedacht um das Spiel Direkt zu Starten
                     * In der Deutschen Version wird das letzte oder nach dem Neustart das
                     * Default Spiel gestartet.
                     */
    Stop,           ///< Stop Taste. Zum Stopen eines eines laufenden Vorgangs
    EStop,          /**
                     * Sofortiger Stop des Gerätes. Antrieb wird Direkt in **NOTAUS** gesetzt
                     */
    Up,             ///< Pfeil Hoch
    Down,           ///< Pfeil Runter
};

/**
 * Definition der Möglichen Handle Typen.
 * \ingroup message
 */
enum class EHandleType : TUint32 {
    Unknown,        ///< Type des Handle ist Unbekannt
    Arm,            ///< Es handelt sich um Arm Handle (Arm Training)
    Leg,            ///< Es handelt sich ium Beim Handle (Bein Training)
    NotDetected     ///< Es konnte noch nicht Festgestellt werden um welchen Handle Type es sich Handelt.
};

/**
 * Position des handle.
 * \ingroup message
 */
enum class EHandlePosition : TUint32 {
  Unknown,          ///< Die Position ist Unbekannt
  Small,            ///< Das handle befindet sich auf den kleinsten Durchmesser
  Medium,           ///< Das Handle befindet sich auf den Mittleren Durchmesser
  Large,            ///< Das Handle befindet sich auf den Äusseren Durchmesser
  NotDetected       ///< Es konnte noch nicht Festgestellt werden auf welcher Position sich das Handle Befindet
};


/**
 * Daten die von der Motor Steuerung Zyklisch geschickt werden.
 *
 * Interval der Nachricht Abhängig von Geräte Type
 * - bemo
 *      - 30 MSec
 * - torro
 *      - 50 MSec
 * \dot
 * digraph example {
 * Drive -> CyclinInferce -> Ui
 * }
 * \enddot
 *
 * \ingroup message
 */
struct DriveData {
    TRpm    mRpm = 0.f;         ///< Aktuelle Rotations Geschwindigkeit
    TNewtonMeter mTorque = 0.f; ///< Aktuelle Drehmoment
    TNewton mForce = 0.f;       ///< Aktuelle Kraft
    TSymmetry mSymmetry= 0.5f;  ///< Aktuell Berechneter Wert der Symmetry
    TWatt mPower = 0.f;         ///< Aktuell geleistete Arbeit
    TAngle mAngle = 0.f;        ///< Aktuelle Position des Handle
    TInt32 mTurns = 0;          /**<
                                 * Anzahl der Umdrehungen
                                 * \todo Was passiert wenn rückwärts gedreht wird ?
                                 */
    TInt16 mUserActive = 0;     /**<
                                 * Zeigt an das der Anwedner Aktiv das Gerät benutzt.
                                 * \todo Was für Werte sind Möglich ?
                                 */

    EHandleType mHandleTypeLeft;            ///< Aktueller Handle Type an der Linken Seite
    EHandleType mHandleTypeRight;           ///< Aktueller Handle Type an der Rechten Seite
    EHandlePosition mHandlePositionLeft;    ///< Aktuelle Handle Position an der Linken Seite
    EHandlePosition mHandlePositionRight;   ///< Aktuelle Hanlde Position an der Rehcten Seite
};

/**
 * Mogliche Betriebszustandes des Antriebs
 * \ingroup message
 * \todo Es muss noch Beschrieben werden was die Betriebsmodes machen
 * und was für Parameter dort gesetzt werden können.
 */
enum class EDriveMode {
  Honey,                    ///< Sicherheits Zustands
  Therapy,                  ///< Ein mode zum Therapieren ?
  IsokineticTherapy,        ///< Ein Mode zum Therapieren nach ISO Norm (haha)
  GearRatioDetermination,   ///< Ein Mode zum Therapieren, aber nur mit den richtigen Klamotten Verhältnis (hoho)
};

/**
 * Daten mit den der Antrieb angesteuert wird.
 * Versetzt den Antrieb in einen Betriebsmode.
 *
 * \dot
 * digraph example {
 * Ui -> CyclinInferce -> Drive
 * }
 * \enddot
 * \ingroup message
 */
struct DriveParameter {
    EDriveMode m_mode = EDriveMode::Honey;      ///< Gibt an welchen Betriebszustand der Antrieb annimmt
    TRpm m_speed = 0.;                          ///< Welchen Umdrehungsgeschwindigkeit soll der Antrieb haben
    TNewton m_maxBrakeForce = 0.;               ///< Kraft
    TNewton m_maxDriveForce = 0.;               ///< Auch Kraft
    TNewton m_resistance = 0.;                  ///< Gegenkraft
};

/**
 * Liefert die Angabe über den Aktuellen Lift Zustands
 * \dot
 * digraph example {
 * Drive -> CyclinInferce -> Ui
 * }
 * \enddot
 * \ingroup message
 */
struct LiftPosition
{
    TDouble mPosition = 0.;     /**<
                                 * Aktuelle Position des Lifts.
                                 * Die Position wird Relative angegeben und
                                 * kann sich zwischen 0 und 1 bewegen.
                                 * Je nach Gerät Unterscheiden sich die Höhen die
                                 * sich aus der Position ergeben
                                 * - toro
                                 *  - 0 : 31 cm
                                 *  - 1 : 91 cm
                                 *
                                 * \todo bemo Wert noch Eintragen
                                 */
};

}



