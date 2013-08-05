/*
 * Copyright (C) 2013  Daniel Vrátil <dvratil@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "pending-logger-operation.h"
#include "log-manager-private.h"

using namespace KTp;

class PendingLoggerOperation::Private
{
  public:
    QString error;
};

PendingLoggerOperation::PendingLoggerOperation(QObject *parent):
    QObject(parent),
    d(new Private)
{
}

PendingLoggerOperation::~PendingLoggerOperation()
{
    delete d;
}

bool PendingLoggerOperation::hasError() const
{
    return !d->error.isEmpty();
}

QString PendingLoggerOperation::error() const
{
    return d->error;
}

void PendingLoggerOperation::setError(const QString &error)
{
    d->error = error;
}

void PendingLoggerOperation::emitFinished()
{
    Q_EMIT finished(this);

    QTimer::singleShot(0, this, SLOT(deleteLater()));
}

QList<AbstractLoggerPlugin*> PendingLoggerOperation::plugins() const
{
    return LogManager::instance()->d->plugins;
}
