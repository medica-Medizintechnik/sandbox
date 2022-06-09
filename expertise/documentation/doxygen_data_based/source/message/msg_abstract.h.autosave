#pragma once

/**
 * \defgroup message Nachrichten
 *
 * \page pageMessage Nachrichten System
 *
 * Die UI Kommuniziert über das Cycling Interface mit dem Backend das
 * wiederum mit der Hardware in Verbindung steht.
 *
 * Da die Schnittstellen des Cycling Interfaces als offene Ports definiert sind
 * kann von Extern auf diese Zugegrifen werden.
 *
 * \dot
 * digraph example {
 *  ui [ label="UI" ];
 *  ci [ label="Cycling Interface" ];
 *  be [ label="Backend" ];
 *
 *  ui -> ci -> be;
 *
 *  node [shape=record];
 *  hw [ label="Hardware Steuerung" ];
 *
 *  be -> hw;
 *
 *  node [shape=record, color="0.7 0.3 1.0"];
 *  ex [ label="Extern Steuerung" ];
 *  ex -> ci;
 *
 * }
 * \enddot
 *
 * API des Cycling Interfaces
 * - Empfängt
 *  - message::DriveParameter
 * - Sendet
 *  - message::DriveData
 *  - message::LiftPosition
 */
