// JukeBox.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "JukeBoxMachine.h"
#include "SongGroup.h"
#include "Song.h"
#include "SongCompDisplayInfoVisitor.h"

int main()
{
	SongGroup rockSongs = SongGroup("rock songs", "rock and roll");
	SongGroup popSongs = SongGroup("pop songs", "pop songs");
	SongGroup allSongs = SongGroup("all songs" , "");

	
	rockSongs.add(new Song("Linkin Park", "Crawling", std::vector<std::string> { "rock" }));
	rockSongs.add(new Song("Linkin Park", "In the end", std::vector<std::string> { "rock" }));
	
	popSongs.add(new Song("Backstreet Boys", "I want it that way", std::vector<std::string> {"pop"}));
	popSongs.add(new Song("Backstreet Boys", "Show me the meaning", std::vector<std::string> {"pop"}));
	allSongs.add(&rockSongs);
	allSongs.add(&popSongs);
	allSongs.displaySongInfo();

	JukeBoxMachine jukeBox(&allSongs);

	jukeBox.showPlaylist();
	jukeBox.playSong(0, 1);

	std::cout << "visitor" << std::endl;

	SongCompDisplayInfoVisitor songDisplayInfoVisitor;
	allSongs.Accept(songDisplayInfoVisitor);


	system("pause");
    return 0;
}

