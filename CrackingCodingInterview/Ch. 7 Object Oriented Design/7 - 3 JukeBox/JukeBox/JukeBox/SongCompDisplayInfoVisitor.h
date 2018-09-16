#pragma once
#include "Song.h"
#include "SongGroup.h"
#include "SongComponentVisitor.h"


class SongCompDisplayInfoVisitor : public SongComponentVisitor
{
public:
	SongCompDisplayInfoVisitor();
	~SongCompDisplayInfoVisitor();


	void VisitSong(Song* song) {
		song->displaySongInfo();
	};
	void VisitSongGroup(SongGroup* songGroup) {
		songGroup->displaySongInfo();
	};



};