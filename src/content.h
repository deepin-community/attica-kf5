/*
    This file is part of KDE.

    SPDX-FileCopyrightText: 2008 Cornelius Schumacher <schumacher@kde.org>

    SPDX-License-Identifier: LGPL-2.1-only OR LGPL-3.0-only OR LicenseRef-KDE-Accepted-LGPL
*/

#ifndef ATTICA_CONTENT_H
#define ATTICA_CONTENT_H

#include <QList>
#include <QMap>
#include <QSharedDataPointer>
#include <QString>
#include <QUrl>

#include "attica_export.h"
#include "downloaddescription.h"
#include "homepageentry.h"
#include "icon.h"

class QDateTime;

namespace Attica
{
/**
 * @class Content content.h <Attica/Content>
 *
 * Represents a single content
 */
class ATTICA_EXPORT Content
{
public:
    typedef QList<Content> List;
    class Parser;

    /**
     * Creates an empty Content
     */
    Content();

    /**
     * Copy constructor.
     * @param other the Content to copy from
     */
    Content(const Content &other);

    /**
     * Assignment operator.
     * @param other the Content to assign from
     * @return pointer to this Content
     */
    Content &operator=(const Content &other);

    /**
     * Destructor.
     */
    ~Content();

    /**
     * Sets the id of the Content.
     * The id uniquely identifies a Content with the OCS API.
     * @param id the new id
     */
    void setId(const QString &id);

    /**
     * Gets the id of the Content.
     * The id uniquely identifies a Content with the OCS API.
     * @return the id
     */
    QString id() const;

    /**
     * Sets the name of the Content.
     * @param name the new name
     */
    void setName(const QString &name);

    /**
     * Gets the name of the Content.
     * @return the name
     */
    QString name() const;

    /**
     * Sets the rating of the Content.
     * @param rating the new rating, has to be in the range 0-100
     */
    void setRating(int rating);

    /**
     * Gets the rating of the Content.
     * @return the rating in the range 0-100
     */
    int rating() const;

    /**
     * Sets the number of downloads for the Content.
     * @param downloads the new number of downloads
     */
    void setDownloads(int downloads);

    /**
     * Gets the number of downloads for the Content (how often this has been downloaded from the server).
     * @return the number of downloads
     */
    int downloads() const;

    /**
     * Sets the number of comments for the Content.
     * @param numComments the new number of downloads
     */
    void setNumberOfComments(int numComments);

    /**
     * Gets the number of comments for the Content.
     * @return the number of comments
     */
    int numberOfComments() const;

    /**
     * Sets the date and time the Content has been created.
     * @param created the new creation date and time
     */
    void setCreated(const QDateTime &created);

    /**
     * Gets the date and time the Content has been created.
     * @return the date and time of the last update
     */
    QDateTime created() const;

    /**
     * Sets the time the Content has been last updated.
     * @param updated the new date and time of the last update
     */
    void setUpdated(const QDateTime &updated);

    /**
     * Gets the date and time the Content has been last updated.
     * @return the date and time of the last update
     */
    QDateTime updated() const;

    /**
     * A summary description of this content.
     */
    QString summary() const;

    /**
     * A description of this content.
     */
    QString description() const;

    /**
     * A webpage with the detailed description of this content.
     */
    QUrl detailpage() const;

    QString changelog() const;
    QString version() const;
    QString depend() const;

    /**
      Get the details about a download (a content can have multiple links, eg for different distros).
      This is not very helpful if we don't know the allowed numbers.
      */
    DownloadDescription downloadUrlDescription(int number) const;

    /**
      Get all possible downloads.
      This is slow searching through lots of strings, so beware and don't call it too often.
      */
    QList<DownloadDescription> downloadUrlDescriptions() const;

    /**
      Get the details about a home page (a content can have multiple home pages, blog, bugs, ...).
      This is not very helpful if we don't know the allowed numbers.
      */
    HomePageEntry homePageEntry(int number) const;

    /**
      Get all home pages for this content.
      This is slow searching through lots of strings, so beware and don't call it too often.
      */
    QList<HomePageEntry> homePageEntries();

    QString previewPicture(const QString &number = QStringLiteral("1")) const;
    QString smallPreviewPicture(const QString &number = QStringLiteral("1")) const;
    QString license() const;
    QString licenseName() const;
    QString author() const;

    /**
      Get all icons for this content.
      */
    QList<Icon> icons();

    /**
      Get all icons for this content.
      */
    QList<Icon> icons() const;

    /**
     * Set list of icons.
     * @param icons list of icons for this content
     */
    void setIcons(QList<Icon> icons);

    /**
      Get all videos for this content.
      */
    QList<QUrl> videos();
    /**
     * Set list of videos.
     * @param videos list of videos for this content
     */
    void setVideos(QList<QUrl> videos);

    /**
     * Get all the tags for this content
     * @since 5.50
     */
    QStringList tags() const;
    /**
     * Set the list of tags
     * @param tags list of tags for this content
     * @since 5.50
     */
    void setTags(const QStringList &tags);

    /**
     * Add an attribute that is not included in the basis set of attributes exposed by the Content class.
     * If the attribute already exists it gets overwritten.
     * @param key the key of the attribute
     * @param value the value of the attribute
     */
    void addAttribute(const QString &key, const QString &value);

    /**
     * Get an attribute that is not included in the basis set of attributes exposed by the Content class.
     * @param key the key of the attribute
     * @return the value of the attribute with the specified key, or an empty string, if the key has not been found
     */
    QString attribute(const QString &key) const;

    /**
     * Get all attributes that are not included in the basis set of attributes exposed by the Content class.
     * @return the attribute mappings
     */
    QMap<QString, QString> attributes() const;

    /**
     * Checks whether this Content has an id
     * @return @c true if an id has been set, @c false otherwise
     */
    bool isValid() const;

private:
    class Private;
    QSharedDataPointer<Private> d;
};

}

#endif
