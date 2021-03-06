/*  smplayer, GUI front-end for mplayer.
    Copyright (C) 2006-2015 Ricardo Villalba <rvm@users.sourceforge.net>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/


#ifndef INFOREADER_MPLAYER_H
#define INFOREADER_MPLAYER_H

#include "inforeader.h"
#include <QObject>
#include <QList>

class QProcess;


class InfoReaderMplayer : QObject {
	Q_OBJECT

public:
    InfoReaderMplayer( QString mplayer_bin, const QString &snap, QObject * parent = 0);
	~InfoReaderMplayer();

	void getInfo();

	InfoList voList() { return vo_list; };
	InfoList aoList() { return ao_list; };
	InfoList demuxerList() { return demuxer_list; };
	InfoList vcList() { return vc_list; };
	InfoList acList() { return ac_list; };

    int mplayerSVN() { return mplayer_svn; };
//	QString mplayer2Version() { return mplayer2_version; };
//	bool isMplayer2() { return is_mplayer2; };

protected slots:
	virtual void readLine(QByteArray);

protected:
	bool run(QString options);
	void list();

protected:
	QProcess * proc;
	QString mplayerbin;

	InfoList vo_list;
	InfoList ao_list;

	InfoList demuxer_list;
	InfoList vc_list;
	InfoList ac_list;

    int mplayer_svn;
//	QString mplayer2_version;
//	bool is_mplayer2;

private:
	bool waiting_for_key;
	int reading_type;

    QString m_snap;
};

#endif
