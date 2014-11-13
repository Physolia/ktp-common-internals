/*
 * Copyright (C) 2012 David Edmundson <kde@davidedmundson.co.uk>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef KTP_ACCOUNTS_TREE_PROXY_MODEL_H
#define KTP_ACCOUNTS_TREE_PROXY_MODEL_H

#include "abstract-grouping-proxy-model.h"

#include <KTp/Models/ktpmodels_export.h>

#include <TelepathyQt/Types>

namespace KTp {

class KTPMODELS_EXPORT AccountsTreeProxyModel : public KTp::AbstractGroupingProxyModel
{
    Q_OBJECT
public:
    AccountsTreeProxyModel(QAbstractItemModel *sourceModel, const Tp::AccountManagerPtr &accountManager);
    virtual ~AccountsTreeProxyModel();

    virtual QSet<QString> groupsForIndex(const QModelIndex &sourceIndex) const;
    virtual QVariant dataForGroup(const QString &group, int role) const;

private Q_SLOTS:
    void onAccountChanged();
    void onAccountAdded(const Tp::AccountPtr &account);
    void onAccountRemoved(const Tp::AccountPtr &account);

private:
    class Private;
    Private *d;

};

}

#endif // ACCOUNTSTREEPROXYMODEL_H
