/////////////////////////////////////////////////////////////////////////////////////////
//
// gro is protected by the UW OPEN SOURCE LICENSE, which is summarized here.
// Please see the file LICENSE.txt for the complete license.
//
// THE SOFTWARE (AS DEFINED BELOW) AND HARDWARE DESIGNS (AS DEFINED BELOW) IS PROVIDED
// UNDER THE TERMS OF THIS OPEN SOURCE LICENSE (“LICENSE”).  THE SOFTWARE IS PROTECTED
// BY COPYRIGHT AND/OR OTHER APPLICABLE LAW.  ANY USE OF THIS SOFTWARE OTHER THAN AS
// AUTHORIZED UNDER THIS LICENSE OR COPYRIGHT LAW IS PROHIBITED.
//
// BY EXERCISING ANY RIGHTS TO THE SOFTWARE AND/OR HARDWARE PROVIDED HERE, YOU ACCEPT AND
// AGREE TO BE BOUND BY THE TERMS OF THIS LICENSE.  TO THE EXTENT THIS LICENSE MAY BE
// CONSIDERED A CONTRACT, THE UNIVERSITY OF WASHINGTON (“UW”) GRANTS YOU THE RIGHTS
// CONTAINED HERE IN CONSIDERATION OF YOUR ACCEPTANCE OF SUCH TERMS AND CONDITIONS.
//
// TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION
//
// Epithelial was developed by Liana Merk, Murray Lab Caltech
// Adapted from Yeast class

#ifndef EPITHELIAL_H
#define EPITHELIAL_H

#include "Micro.h"

class Epithelial : public Cell {

 public:
  Epithelial ( World * w, float x, float y, float a, float v);
  void render ( Theme * theme, GroPainter * painter  );
  void update ( void );
  float radius ( void ) { return world->get_param("epithelial_radius"); }
  void inc_volume ( float dv ) { volume += dv; }
  float get_volume ( void ) { return volume; }
  inline float rad_to_vol ( float r ) { return 4.18879 * r*r*r; }
  void set_parent_cell ( Epithelial * p ) { parent_cell = p; }
  float get_fluorescence ( int i ) { return (float) get_rep(i) / volume; }
  float get_size ( void ) { return volume; }

 private:
  float volume;
  Epithelial * parent_cell;
  cpConstraint * cord;

};

#endif // EPITHELIAL_H
