/*
    This file is part of KDE.

    SPDX-FileCopyrightText: 2010 Sebastian Kügler <sebas@kde.org>

    SPDX-License-Identifier: LGPL-2.1-only OR LGPL-3.0-only OR LicenseRef-KDE-Accepted-LGPL
*/

#ifndef ATTICA_PROJECTPARSER_H
#define ATTICA_PROJECTPARSER_H

#include "parser.h"
#include "project.h"

namespace Attica
{
class Q_DECL_HIDDEN Project::Parser : public Attica::Parser<Project>
{
private:
    Project parseXml(QXmlStreamReader &xml) override;
    QStringList xmlElement() const override;
};

}

#endif
