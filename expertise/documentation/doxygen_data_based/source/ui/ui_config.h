#pragma once

#include "../def.h"

namespace ui {
namespace toro {

/**
 * \ingroup ui
 * \defgroup uiCfg Configuration
 */


/**
 * Angaben über die Benötigten Pathe der Applikation
 * \ingroup ui
 */
struct CfgPaths {
    TUtf8 mQmlRootUrl = "qrc:/qml/MainForm.qml";
        ///< Path auf die Root QML Datei Sample \sa mQmlImportPath
    TUtf8 mQmlImportPath = "qrc:/qml/imports/";
        /**<
         * Path in dem QML seine Import sucht.
         * Sample:
         *  - Interne Ressource : "qrc:/qml/imports/"
         *  - Extern Ressource : "file:/${PROJECTSDIR}/desktop/frontend/ui/main/resources/qml/MainForm.qml"
         */
};


/**
 * \ingroup uiCfg
 * Konfigurations Root für die Toro HMI Software.
 */
struct Cfg{
    CfgPaths mPaths;    ///< Konfirguation der Pathe des Projekts
};

}
}
