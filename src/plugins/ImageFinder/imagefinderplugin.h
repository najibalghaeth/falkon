/* ============================================================
* ImageFinder plugin for Falkon
* Copyright (C) 2016 Vladislav Tronko <innermous@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#ifndef IMAGEFINDERPLUGIN_H
#define IMAGEFINDERPLUGIN_H

#include "plugininterface.h"

class ImageFinder;
class ImageFinderSettings;

class ImageFinderPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)

    Q_PLUGIN_METADATA(IID "Falkon.Browser.plugin.ImageFinderPlugin")

public:
    explicit ImageFinderPlugin();

    DesktopFile metaData() const override;
    void init(InitState state, const QString &settingsPath) override;
    void unload() override;
    bool testPlugin() override;
    void showSettings(QWidget *parent) override;

    void populateWebViewMenu(QMenu *menu, WebView *view, const WebHitTestResult &r) override;

private:
    ImageFinder *m_finder;
    QPointer<ImageFinderSettings> m_settings;
};

#endif // IMAGEFINDERPLUGIN_H
