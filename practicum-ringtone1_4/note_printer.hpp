#ifndef _NOTE_PRINTER_HPP
#define _NOTE_PRINTER_HPP

#include "note_player.hpp"


class note_printer : public note_player {

public: 
   
   void play( const note & n ) override;
};

#endif
