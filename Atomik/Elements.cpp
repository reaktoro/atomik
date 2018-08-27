
// C++ includes
#include <string>
#include <unordered_map>

namespace Atomik {

class Element
{
public:
    Element();

private:
    /// The symbol of the chemical element (e.g., "H", "O", "C", "Na")
    std::string m_symbol;

    /// The name of the chemical element (e.g., "Hydrogen", "Oxygen")
    std::string m_name;

    /// The atomic number of the chemical element
    std::size_t m_atomic_number;

    /// The atomic weight (or molar mass) of the chemical element (in unit of g/moo)
    double m_atomic_weight;
    double m_electronegativity;

};
const std::unordered_map<std::string , Element> elements = {
    { "H"  , "Hydrogen"      , 1   , 0.001007940 , 2.20 } ,
    { "He" , "Helium"        , 2   , 0.004002602 , 0.00 } ,
    { "Li" , "Lithium"       , 3   , 0.006941000 , 0.98 } ,
    { "Be" , "Beryllium"     , 4   , 0.009012180 , 1.57 } ,
    { "B"  , "Boron"         , 5   , 0.010811000 , 2.04 } ,
    { "C"  , "Carbon"        , 6   , 0.012011000 , 2.55 } ,
    { "N"  , "Nitrogen"      , 7   , 0.014006740 , 3.04 } ,
    { "O"  , "Oxygen"        , 8   , 0.015999400 , 3.44 } ,
    { "F"  , "Fluorine"      , 9   , 0.018998403 , 3.98 } ,
    { "Ne" , "Neon"          , 10  , 0.020179700 , 0.00 } ,
    { "Na" , "Sodium"        , 11  , 0.022989768 , 0.93 } ,
    { "Mg" , "Magnesium"     , 12  , 0.024305000 , 1.31 } ,
    { "Al" , "Aluminum"      , 13  , 0.026981539 , 1.61 } ,
    { "Si" , "Silicon"       , 14  , 0.028085500 , 1.90 } ,
    { "P"  , "Phosphorus"    , 15  , 0.030973762 , 2.19 } ,
    { "S"  , "Sulfur"        , 16  , 0.032066000 , 2.58 } ,
    { "Cl" , "Chlorine"      , 17  , 0.035452700 , 3.16 } ,
    { "Ar" , "Argon"         , 18  , 0.039948000 , 0.00 } ,
    { "K"  , "Potassium"     , 19  , 0.039098300 , 0.82 } ,
    { "Ca" , "Calcium"       , 20  , 0.040078000 , 1.00 } ,
    { "Sc" , "Scandium"      , 21  , 0.044955910 , 1.36 } ,
    { "Ti" , "Titanium"      , 22  , 0.047880000 , 1.54 } ,
    { "V"  , "Vanadium"      , 23  , 0.050941500 , 1.63 } ,
    { "Cr" , "Chromium"      , 24  , 0.051996100 , 1.66 } ,
    { "Mn" , "Manganese"     , 25  , 0.054938050 , 1.55 } ,
    { "Fe" , "Iron"          , 26  , 0.055847000 , 1.83 } ,
    { "Co" , "Cobalt"        , 27  , 0.058933200 , 1.88 } ,
    { "Ni" , "Nickel"        , 28  , 0.058693400 , 1.91 } ,
    { "Cu" , "Copper"        , 29  , 0.063546000 , 1.90 } ,
    { "Zn" , "Zinc"          , 30  , 0.065390000 , 1.65 } ,
    { "Ga" , "Gallium"       , 31  , 0.069723000 , 1.81 } ,
    { "Ge" , "Germanium"     , 32  , 0.072610000 , 2.01 } ,
    { "As" , "Arsenic"       , 33  , 0.074921590 , 2.18 } ,
    { "Se" , "Selenium"      , 34  , 0.078960000 , 2.55 } ,
    { "Br" , "Bromine"       , 35  , 0.079904000 , 2.96 } ,
    { "Kr" , "Krypton"       , 36  , 0.083800000 , 0.00 } ,
    { "Rb" , "Rubidium"      , 37  , 0.085467800 , 0.82 } ,
    { "Sr" , "Strontium"     , 38  , 0.087620000 , 0.95 } ,
    { "Y"  , "Yttrium"       , 39  , 0.088905850 , 1.22 } ,
    { "Zr" , "Zirconium"     , 40  , 0.091224000 , 1.33 } ,
    { "Nb" , "Niobium"       , 41  , 0.092906380 , 1.60 } ,
    { "Mo" , "Molybdenum"    , 42  , 0.095940000 , 2.16 } ,
    { "Tc" , "Technetium"    , 43  , 0.097907200 , 1.90 } ,
    { "Ru" , "Ruthenium"     , 44  , 0.101070000 , 2.20 } ,
    { "Rh" , "Rhodium"       , 45  , 0.102905500 , 2.28 } ,
    { "Pd" , "Palladium"     , 46  , 0.106420000 , 2.20 } ,
    { "Ag" , "Silver"        , 47  , 0.107868200 , 1.93 } ,
    { "Cd" , "Cadmium"       , 48  , 0.112411000 , 1.69 } ,
    { "In" , "Indium"        , 49  , 0.114818000 , 1.78 } ,
    { "Sn" , "Tin"           , 50  , 0.118710000 , 1.96 } ,
    { "Sb" , "Antimony"      , 51  , 0.121760000 , 2.05 } ,
    { "Te" , "Tellurium"     , 52  , 0.127600000 , 2.10 } ,
    { "I"  , "Iodine"        , 53  , 0.126904470 , 2.66 } ,
    { "Xe" , "Xenon"         , 54  , 0.131290000 , 0.00 } ,
    { "Cs" , "Cesium"        , 55  , 0.132905430 , 0.79 } ,
    { "Ba" , "Barium"        , 56  , 0.137327000 , 0.89 } ,
    { "La" , "Lanthanum"     , 57  , 0.138905500 , 1.10 } ,
    { "Ce" , "Cerium"        , 58  , 0.140115000 , 1.12 } ,
    { "Pr" , "Praseodymium"  , 59  , 0.140907650 , 1.13 } ,
    { "Nd" , "Neodymium"     , 60  , 0.144240000 , 1.14 } ,
    { "Pm" , "Promethium"    , 61  , 0.144912700 , 0.00 } ,
    { "Sm" , "Samarium"      , 62  , 0.150360000 , 1.17 } ,
    { "Eu" , "Europium"      , 63  , 0.151965000 , 0.00 } ,
    { "Gd" , "Gadolinium"    , 64  , 0.157250000 , 1.20 } ,
    { "Tb" , "Terbium"       , 65  , 0.158925340 , 1.20 } ,
    { "Dy" , "Dysprosium"    , 66  , 0.162500000 , 0.00 } ,
    { "Ho" , "Holmium"       , 67  , 0.164930320 , 1.23 } ,
    { "Er" , "Erbium"        , 68  , 0.167260000 , 1.24 } ,
    { "Tm" , "Thulium"       , 69  , 0.168934210 , 1.25 } ,
    { "Yb" , "Ytterbium"     , 70  , 0.173040000 , 1.10 } ,
    { "Lu" , "Lutetium"      , 71  , 0.174967000 , 1.27 } ,
    { "Hf" , "Hafnium"       , 72  , 0.178490000 , 1.30 } ,
    { "Ta" , "Tantalum"      , 73  , 0.180947900 , 1.50 } ,
    { "W"  , "Tungsten"      , 74  , 0.183840000 , 1.70 } ,
    { "Re" , "Rhenium"       , 75  , 0.186207000 , 1.90 } ,
    { "Os" , "Osmium"        , 76  , 0.190230000 , 2.20 } ,
    { "Ir" , "Iridium"       , 77  , 0.192220000 , 2.20 } ,
    { "Pt" , "Platinum"      , 78  , 0.195080000 , 2.28 } ,
    { "Au" , "Gold"          , 79  , 0.196966540 , 2.54 } ,
    { "Hg" , "Mercury"       , 80  , 0.200590000 , 2.00 } ,
    { "Tl" , "Thallium"      , 81  , 0.204383300 , 1.62 } ,
    { "Pb" , "Lead"          , 82  , 0.207200000 , 1.80 } ,
    { "Bi" , "Bismuth"       , 83  , 0.208980370 , 2.02 } ,
    { "Po" , "Polonium"      , 84  , 0.208982400 , 2.00 } ,
    { "At" , "Astatine"      , 85  , 0.209987100 , 2.20 } ,
    { "Rn" , "Radon"         , 86  , 0.222017600 , 0.00 } ,
    { "Fr" , "Francium"      , 87  , 0.223019700 , 0.70 } ,
    { "Ra" , "Radium"        , 88  , 0.226025400 , 0.90 } ,
    { "Ac" , "Actinium"      , 89  , 0.227027800 , 1.10 } ,
    { "Th" , "Thorium"       , 90  , 0.232038100 , 1.30 } ,
    { "Pa" , "Protactinium"  , 91  , 0.231035880 , 1.50 } ,
    { "U"  , "Uranium"       , 92  , 0.238028900 , 1.38 } ,
    { "Np" , "Neptunium"     , 93  , 0.237048000 , 1.36 } ,
    { "Pu" , "Plutonium"     , 94  , 0.244064200 , 1.28 } ,
    { "Am" , "Americium"     , 95  , 0.243061400 , 1.30 } ,
    { "Cm" , "Curium"        , 96  , 0.247070300 , 1.30 } ,
    { "Bk" , "Berkelium"     , 97  , 0.247070300 , 1.30 } ,
    { "Cf" , "Californium"   , 98  , 0.251079600 , 1.30 } ,
    { "Es" , "Einsteinium"   , 99  , 0.252083000 , 1.30 } ,
    { "Fm" , "Fermium"       , 100 , 0.257095100 , 1.30 } ,
    { "Md" , "Mendelevium"   , 101 , 0.258100000 , 1.30 } ,
    { "No" , "Nobelium"      , 102 , 0.259100900 , 1.30 } ,
    { "Lr" , "Lawrencium"    , 103 , 0.262110000 , 0.00 } ,
    { "Rf" , "Rutherfordium" , 104 , 0.261000000 , 0.00 } ,
    { "Db" , "Dubnium"       , 105 , 0.262000000 , 0.00 } ,
    { "Sg" , "Seaborgium"    , 106 , 0.266000000 , 0.00 } ,
    { "Bh" , "Bohrium"       , 107 , 0.264000000 , 0.00 } ,
    { "Hs" , "Hassium"       , 108 , 0.269000000 , 0.00 } ,
    { "Mt" , "Meitnerium"    , 109 , 0.268000000 , 0.00 } ,
    { "Ds" , "Darmstadtium"  , 110 , 0.269000000 , 0.00 } ,
    { "Rg" , "Roentgenium"   , 111 , 0.272000000 , 0.00 } ,
    { "Cn" , "Copernicium"   , 112 , 0.277000000 , 0.00 } ,
    { "Nh" , "Nihonium"      , 113 , 0.000000000 , 0.00 } ,
    { "Fl" , "Flerovium"     , 114 , 0.289000000 , 0.00 } ,
    { "Mc" , "Moscovium"     , 115 , 0.000000000 , 0.00 } ,
    { "Lv" , "Livermorium"   , 116 , 0.000000000 , 0.00 } ,
    { "Ts" , "Tennessine"    , 117 , 0.000000000 , 0.00 } ,
    { "Og" , "Oganesson"     , 118 , 0.000000000 , 0.00 } ,
};

} // namespace Atomik