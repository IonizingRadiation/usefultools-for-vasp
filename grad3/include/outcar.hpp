#pragma once

#ifndef OUTCAR_H
#define OUTCAR_H

#if __cplusplus < 201103L
  #error "DEPRECATED COMPILER, USE GCC4.9 OR HIGHER"
#endif

#include <base.hpp>
#include <poscar.hpp>
#include <stringops.hpp>

namespace ionizing{ 

#define UNIT_TEST

#ifdef UNIT_TEST
#define private public  // Just for unit_test
#endif

class OUTCAR {
public:
  /*
   * OUTCAR(std::istream& is);
   * OUTCAR(const char* file_name);
   * ~OUTCAR();
   */

/*
 * Parse type of Pseudo Potentials
 */



public:
  VecStr parseElems(const VecStr& lines, 
                    const string& content,
                    const int     startline =  0,
                          int     endline   = -1);
private:
  VecStr parse_elems(const VecStr& lines);
  const string& file_to_string(std::istream& is);
  const VecStr& string_to_vecstr(const string& content);

  VecStr test_parse_elem(std::istream& is);

/*
 * Parse Lattice Vectors
 */
public:
  Mat33d parseLatticeVectors(const VecStr& lines, 
                             const int     startline =  0, 
                                   int     endline   = -1);
private:
  Mat33d parse_lattice_vectors(const VecStr& lines);

/*
 * Parse Atom initial Positions
 */



/*
 * Parse K-Point Path
 */
public:
  MatX3d parseKPoints(const VecStr& lines,
                      const int     startline =  0,
                            int     endline   = -1);
private:
  int        _NKPTS;
  MatX3d     _kpoints;
  const int&    parse_nkpts(const string& line);
  const MatX3d& parse_kpoints(const VecStr& lines);



public:
// POSCAR info without selective dynamics
  struct mini_POSCAR {
    using VecElem = VecT<Element>;

    string Header;
    Mat33d LatticeVectors;    
    VecElem ElementVector;

    void print_to_file();
  };

private:
// raw text
  string _content;
  VecStr _contentVector;

// parsed data
  string _filename;
  VecStr _Elems;
  
// INCAR involved parameters
  int __current_line;

  int _EDIFF;
  int _EDIFFG;
  int _ENCUT;
  int _IBRION;
  int _ISIF;
  int _ISPIN;
  int _LNONCOLLINEAR;
  int _LORBIT;
  int _LSORBIT;
  int _NBANDS;
  int _NELMIN;
  int _NIONS;
  int _NSW;

  int _nElems;
  int _nIterations;
  int _nSteps;

  double _tottalEnergy;
  double _lastEnergy;
  double _cpuTime;
  double _deltaE;
  double _magmom;
  double _volume;
  double _totaltime;
  double _average;
  double _maxForce;
  double _accuracy;

private:

};







}
#endif
