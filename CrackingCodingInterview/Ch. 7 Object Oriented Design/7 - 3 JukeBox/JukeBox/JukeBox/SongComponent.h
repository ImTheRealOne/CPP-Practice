#pragma once

#include <string>
#include <vector>
#include <iostream>

class SongComponentVisitor;

class SongComponent
{
public:
	
	virtual ~SongComponent();
	virtual SongComponent* getComposite() { return 0; }

	virtual void add(SongComponent*) {}
	virtual void remove(SongComponent*) {}
	virtual std::string getSongTitle() { return ""; }
	virtual std::string getArtistName() { return ""; }
	virtual void displaySongInfo() {};
	virtual void Accept(SongComponentVisitor&) {};
protected:
	SongComponent();
};

