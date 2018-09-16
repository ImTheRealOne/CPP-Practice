#pragma once
class SongGroup;
class Song;
class SongComponentVisitor
{
public:
	virtual ~SongComponentVisitor();

	virtual void VisitSong(Song* song) {}
	virtual void VisitSongGroup(SongGroup* songGroup) {}

protected:
	SongComponentVisitor();
};

