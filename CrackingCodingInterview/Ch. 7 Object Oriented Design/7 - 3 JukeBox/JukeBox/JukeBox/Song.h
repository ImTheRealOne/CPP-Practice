#pragma once

#include "SongComponent.h"
#include "SongComponentVisitor.h"

class Song : public SongComponent
{
public:
	Song();
	Song(std::string newArtist, std::string newSongTitle, std::vector<std::string> newGenre) :
		artist(newArtist), songTitle(newSongTitle), genres(newGenre) {};
	~Song();

	std::string getSongTitle() { return songTitle; }
	std::string getArtistName() { return artist; }
	std::vector<std::string> getGenre() { return genres; }
	SongComponent* getComposite() { return 0; }
	void displaySongInfo() {
		std::cout << "Title : " << songTitle << std::endl;
		std::cout << "Artist : " << artist << std::endl;
		std::cout << "Genre : ";
		for (std::string genre : genres) {
			std::cout << genre << "  ";
		}
		std::cout << std::endl;
	}

	void Accept(SongComponentVisitor &visitor) {
		visitor.VisitSong(this);
	}
	
private:
	std::string artist;
	std::string songTitle;
	std::vector<std::string> genres;
};

