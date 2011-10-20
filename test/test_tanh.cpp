///////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2002 - 2011.
//  Copyright 2011 John Maddock. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_
//
// This work is based on an earlier work:
// "Algorithm 910: A Portable C++ Multiple-Precision System for Special-Function Calculations",
// in ACM TOMS, {VOL 37, ISSUE 4, (February 2011)} (C) ACM, 2011. http://doi.acm.org/10.1145/1916461.1916469

#include <boost/detail/lightweight_test.hpp>
#include <boost/array.hpp>
#include "test.hpp"

#if !defined(TEST_MPF50) && !defined(TEST_MPF) && !defined(TEST_BACKEND) && !defined(TEST_MPZ) && !defined(TEST_E_FLOAT) && !defined(TEST_MPFR) && !defined(TEST_MPFR_50) && !defined(TEST_MPQ)
#  define TEST_MPF50
//#  define TEST_MPF
#  define TEST_BACKEND
#  define TEST_E_FLOAT

#ifdef _MSC_VER
#pragma message("CAUTION!!: No backend type specified so testing everything.... this will take some time!!")
#endif
#ifdef __GNUC__
#pragma warning "CAUTION!!: No backend type specified so testing everything.... this will take some time!!"
#endif

#endif

#if defined(TEST_MPF50)
#include <boost/multiprecision/gmp.hpp>
#endif
#if defined(TEST_MPFR_50)
#include <boost/multiprecision/mpfr.hpp>
#endif
#ifdef TEST_BACKEND
#include <boost/multiprecision/concepts/mp_number_architypes.hpp>
#endif
#ifdef TEST_E_FLOAT
#include <boost/multiprecision/e_float.hpp>
#endif

template <class T>
void test()
{
   static const boost::array<T, 51u> data =
   {{
           T("0.32137338579537729992840434899278935725496267444911714908205287462634251052210833615032073534299473485492692600156322137421801432333125051088723502425037485776412801577568405892077585206768190530859883094571475323319480739773193974206966728764224286661945738178210577326172938196062277314761537881936346874075881338768208490193827960565412814349738654540520356903367084438822830345189856017860672463017"),
           T("0.98628073997374759901559180515206275902189609982907214282364143439537215491113710345866034807991101303183938339561499559327886956280789743287824488269072297413440935381715378233031399015496124706604318545539544610760151756970229801074280545428642122005982857974921606264103186878499260552388713716032507770319550435738767597150644370033277228635793175246197730488375240713357827246166262087899961098648"),
           T("0.99999659728082161113542951278514830809677661658635225532792520501703544628367875293677270218317428676793098034276042396396797568103263882451732810190507733063467333056356770774002596898762991629653041854653269824642873291146068535300466473399592751219449187768646625229500705182676930009096545254478199838990703077597971823456671241141900968900216742636822174010867343154474773040184900973368250708724"),
           T("0.9999999999846483268200051609594321550129159997920576480976206867496512752486590660437091205989616108531910897733432934135954788151766561209164605337537937873588006552145390152387235783207736999759875845070169747521389728857476525437483543080651125798739562649414879487621858466223255239845627205850217328574865852922872737234283038190096982410137471391847466112651349436875974689271288261759782261321"),
           T("0.9999999999999999987314527242099750648171958211319474558707792311593804963057878814487720997303512134007272111464990650500302215773762906820778949397525329109311974741708703536680512747226155618703318739024344621256722269608969415280035337052044425138281821760268269187377517243951584969175035549994883451471918693502477485385682884154959809285569290940740978684264145737164182111806308430952867505356"),
           T("0.9999999999999999999999999980800953069847308586840237590563929855339557065536765765234844240789584487443451033349994294426525006157530320529970966048109743850154174651033567146346966529198814047607015842020039899630884318521543225160212193994911746894335846264878066530266737005606770102869237101848445559941638381625615207320468184414917265299980278164193202897754476112968080358662232635784904263624"),
           T("0.9999999999999999999999999999999999999467800140220866754762922747687784133233134010432889959570821554455247528344437918197518545105332713456859236726383195243056599177018396579766073961540714510399202497404647103138524118065391185503678895059096790300665805648569647351935897874460587855127436472608470703384261586158923066272124216158518232588330799027603391275039552776308636189531809031683723259525"),
           T("0.9999999999999999999999999999999999999999999999999729795912960133359928587562229512337339217831178574875626619226954752643039860388090399659478676726654102118545764943682017611574275691203710439707807193180604656837503862242700430179591666329131728631752773789406064618682879167351725013888294859467540832310795515139677375807407622028485242969471516812171475098378942187864794497220152019202351747432"),
           T("0.9999999999999999999999999999999999999999999999999999999999999997487354938310440650220692519525261552411539996830587326435051159231522052011310872619940247463640019105467860778515384738650636054646551611609757125760437266415865214306396520500343113189907306851418957620080971645943305760132385139924583154317156560414548076370893360020924960120441059315311380109752919823616149973862196846266297710225"),
           T("0.9999999999999999999999999999999999999999999999999999999999999999999999999999999572050575304159358359221596743379014313563214857593401545331495211888415913558896516895286943572966865708195832339959764445194449615969154689769557903166971249521898883489362426386924297872088925852892350150865941427355319827260914834268754732102528105919811851193667193380541054520023003326858641189063542651960743457613"),
           T("0.9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999998665016733514821204959171836698281165918083005790816030823236096080522860514417075411055633676502699904415882389102672678124683084429720879962355892225321369091298491658349178472270952759208443767848312111069127329160464884932271685986610697222434145553035947750809388321614695213754318979469071722942883"),
           T("0.999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999992372516628147584832950728021842198359205201519966391076994594773600474674435473005118571751514446148292787696117866094991476340344341061706866751156257825144909115117822189019766805825304055482958970512463798453229341693148012213183553546720540880444569824125592343803193018989122964"),
           T("0.9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999920180539244323143459416025663362517256166793900312667214543096238752838226369161775531456005541374878274529461511286842988937830155704737448202558382612829022464635400289328916240002670783433827234852858267621807568393874737879853500598862298495727481132883728328"),
           T("0.9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999998470116425957155787153557938061034698436461173594805292722874130433614266475136267606498346730583487791266503943659174886554170377537630914770998114573340081594827150737005158607830579000912020838690230498119348251553312722575955142752845289"),
           T("0.9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999462931048083476382670449719737943481963930626760625326765703815392249622625483433043363664396638162612437367800102332819699131841317348173451308570776544874933173719394861336636728378134900422312720743996219523365098"),
           T("0.9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999996546783689748726752364896615532860288057097437452774779386074906915819380531729493071959232887620213723607155628959529584572083388979892309086717786559916703004365603135284141639480887703759"),
           T("0.9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999593332381019647939423999969519583099837564321056588766269967853479478603122899456262904869063959564274215899007623362296377022418464303752396325625838280378647335"),
           T("0.9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999122842714667567128203355585346559126606029196080721845292399104475997315344844970601651757832506169948906646054332493537761143729664"),
           T("0.9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999965347272050374435790597917065458623422102880662825928396981295898014081371503733411536311258910851858"),
           T("0.9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999974926240515037403282500845454464621558236030794140169313830052413917"),
           T("0.9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999667705192725716176070161727364499"),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
           T("1."),
   }};

   T eg = "5.77215664901532860606512090082402431042159335939923598805767234884867726777664670936947063291746749514631447249807082480960504014486542836224173997644923536253500333742937337737673942792595258247094916008735203948165670853233151776611528621199501507984793745085705740029921354786146694029604325421519e-1";

   unsigned max_err = 0;
   for(unsigned k = 0; k < data.size(); k++)
   {
      const T x = eg + k;
      T val = boost::multiprecision::tanh(x * x);
      T e = relative_error(val, data[k]);
      unsigned err = e.template convert_to<unsigned>();
      if(err > max_err)
         max_err = err;
   }
   std::cout << "Max error was: " << max_err << std::endl;
   BOOST_TEST(max_err < 10);
}


int main()
{
#ifdef TEST_BACKEND
   test<boost::multiprecision::mp_number<boost::multiprecision::concepts::mp_number_backend_real_architype> >();
#endif
#ifdef TEST_MPF50
   test<boost::multiprecision::mpf_real_50>();
   test<boost::multiprecision::mpf_real_100>();
#endif
#ifdef TEST_MPFR_50
   test<boost::multiprecision::mpfr_real_50>();
   test<boost::multiprecision::mpfr_real_100>();
#endif
#ifdef TEST_E_FLOAT
   test<boost::multiprecision::e_float>();
#endif
   return boost::report_errors();
}



