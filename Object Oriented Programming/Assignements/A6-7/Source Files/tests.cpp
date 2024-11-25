//#include "tests.h"
//#include <cassert>
//#include <stdexcept>
//#include <string>
//#include <iostream>
//#include <algorithm>
//
//void Tests::testTrenchCoats()
//{
//	TrenchCoat t1{};
//    TrenchCoat t2{ "beige", "https://www.massimodutti.com/ro/trenci-scurt-negru-din-amestec-de-bumbac-l06765821", 38, 10, 500 };
//
//	assert(t1.getQuantity() == 0);
//    assert(t1.getColour().empty());
//    assert(t1.getPhotograph().empty());
//
//	assert(t2.getColour() == "beige");
//	assert(t2.getPrice() == 500);
//    assert(t2.getPhotograph() == "https://www.massimodutti.com/ro/trenci-scurt-negru-din-amestec-de-bumbac-l06765821");
//    assert(t2.getQuantity() == 10);
//    assert(t2.getSize() == 38);
//
//    assert((t1==t2) == false);
//	t1.setPrice(500);
//    assert(t1.getPrice() == 500);
//
//    t1.setColour("beige");
//	assert(t1.getColour() == "beige");
//
//    t1.setQuantity(10);
//    assert(t1.getQuantity() == 10);
//
//    t1.setPhotograph(t2.getPhotograph());
//	assert(t1.getPhotograph() == t2.getPhotograph());
//
//    t1.setSize(38);
//    assert(t1.getSize() == 38);
//
//	assert(t1 == t2);
//
//    TrenchCoat t3{t1};
//    assert(t1.getPhotograph() == t3.getPhotograph());
//    assert(t1 == t3);
//
//    // test validate
//    t3.setSize(1);
//    try{
//        t3.validateTrenchCoat();
//        assert(false);
//    }
//    catch(const std::invalid_argument& exc){
//        assert(true);
//    }
//    try{
//        t2.validateTrenchCoat();
//        assert(true);
//    }
//    catch(const std::invalid_argument& exc) {
//        assert(false);
//    }
//    t2.setPrice(-1);
//    try{
//        t2.validateTrenchCoat();
//        assert(false);
//    }
//    catch(const std::invalid_argument& exc){
//        assert(true);
//    }
//
//    t1.setQuantity(-10);
//    try{
//        t1.validateTrenchCoat();
//        assert(false);
//    }
//    catch(const std::invalid_argument& exc){
//        assert(true);
//    }
//
//    // test assignment
//    TrenchCoat t4{};
//    t4 = t3;
//    assert(t4 == t3);
//    t2 = t4 = t3;
//    assert(t2 == t3);
//    t4 = t4;
//    assert(t4 == t3);
//}
//
//void Tests::testRepository()
//{
//    Repository repo{};
//    assert(repo.getAllTrenchCoats().empty());
//
//    // test add
//    TrenchCoat t1{ "beige", "https://www.massimodutti.com/ro/trenci-scurt-negru-din-amestec-de-bumbac-l06765821", 38, 10, 500 };
//    repo.addTrenchCoat(t1);
//    assert(repo.getAllTrenchCoats().size() == 1);
//    assert(repo.getDatabaseSize() == 1);
//    assert(repo.getAllTrenchCoats()[0] == t1);
//    TrenchCoat t2{ "black", "https://www.massimodutti.com/ro/trenci-scurt-negru-din-amestec-de-bumbac-l06765821", 44, 25, 649 };
//    repo.addTrenchCoat(t2);
//    assert(repo.getAllTrenchCoats().size() == 2);
//    assert(repo.getDatabaseSize() == 2);
//    assert(repo.getAllTrenchCoats()[1] == t2);
//    try{
//        repo.addTrenchCoat(t1);
//        assert(false);
//    }
//    catch(std::invalid_argument& exc){
//        assert(true);
//    }
//
//    // test search
//    assert(repo.getTrenchCoatByPosition(0) == t1);
//    assert(repo.getTrenchCoatByPosition(1) == t2);
//    try{
//        repo.getTrenchCoatByPosition(-1);
//        assert(false);
//    }
//    catch(std::invalid_argument& exc){
//        assert(true);
//    }
//    assert(repo.searchForTrenchCoat(t1) == 0);
//    TrenchCoat t3{ "blue", "https://www.massimodutti.com/ro/trenci-scurt-negru-din-amestec-de-bumbac-l06765821", 36, 15, 250 };
//    assert(repo.searchForTrenchCoat(t3) == -1);
//
//    // test remove
//    try{
//        repo.removeTrenchCoat(t3);
//        assert(false);
//    }
//    catch(std::invalid_argument& exc){
//        assert(true);
//    }
//    repo.removeTrenchCoat(t1);
//    assert(repo.getDatabaseSize() == 1);
//    assert(repo.searchForTrenchCoat(t1) == -1);
//    assert(repo.getTrenchCoatByPosition(0) == t2);
//
//    repo.addTrenchCoat(t3);
//    assert(repo.getTrenchCoatByPosition(1) == t3);
//    repo.removeTrenchCoatByPosition(1);
//    assert(repo.searchForTrenchCoat(t3) == -1);
//    assert(repo.getDatabaseSize() == 1);
//
//    try{
//        repo.removeTrenchCoatByPosition(1);
//        assert(false);
//    }
//    catch(std::invalid_argument& exc){
//        assert(true);
//    }
//
//    // test update
//    repo.updateTrenchCoat(0, t3);
//    assert(repo.getTrenchCoatByPosition(0) == t3);
//    assert(repo.getDatabaseSize() == 1);
//
//    try{
//        repo.updateTrenchCoat(1, t3);
//        assert(false);
//    }
//    catch(std::invalid_argument& exc){
//        assert(true);
//    }
//
//    // test get trench coats by size
//    std::vector<TrenchCoat> d = repo.getTrenchCoatsBySize(38);
//    assert(d.empty());
//    repo.addTrenchCoat(t1);
//    d = repo.getTrenchCoatsBySize(38);
//    assert(d.size() == 1);
//    assert(d[0] == t1);
//}
//
//void Tests::testService()
//{
//    Service s{};
//    assert(s.getTrenchCoatsCount() == 10);
//    assert(s.getAllTrenchCoatsService().size() == 10);
//
//    // test add
//    TrenchCoat t1{ "blue", "https://www.massimodutti.com/ro/trenci-scurt-negru-din-amestec-de-bumbac-l06765821", 38, 10, 500 };
//    s.addTrenchCoatService(t1);
//    assert(s.getTrenchCoatsCount() == 11);
//    assert(s.getAllTrenchCoatsService().size() == 11);
//    assert(s.searchForTrenchCoatService(t1) == 10);
//    assert(s.getTrenchCoatByPositionService(10) == t1);
//
//    try{
//        s.addTrenchCoatService(t1);
//        assert(false);
//    }
//    catch(std::invalid_argument& exc){
//        assert(true);
//    }
//
//    // test remove
//    TrenchCoat t2{ "black", "https://www.massimodutti.com/ro/trenci-scurt-negru-din-amestec-de-bumbac-l06765821", 40, 25, 649 };
//    s.addTrenchCoatService(t2);
//    assert(s.getTrenchCoatsCount() == 12);
//    s.removeTrenchCoatByPositionService(11);
//    assert(s.getTrenchCoatsCount() == 11);
//    assert(s.searchForTrenchCoatService(t2) == -1);
//    try{
//        s.removeTrenchCoatByPositionService(11);
//        assert(false);
//    }
//    catch(std::invalid_argument& exc){
//        assert(true);
//    }
//
//    s.addTrenchCoatService(t2);
//    assert(s.searchForTrenchCoatService(t2) == 11);
//    s.removeTrenchCoatService(t2);
//    assert(s.searchForTrenchCoatService(t2) == -1);
//    assert(s.getTrenchCoatsCount() == 11);
//    try{
//        s.removeTrenchCoatService(t2);
//        assert(false);
//    }
//    catch(std::invalid_argument& exc){
//        assert(true);
//    }
//
//    // test update
//    assert(s.searchForTrenchCoatService(t1) == 10);
//    s.updateTrenchCoatService(t1, t2);
//    assert(s.searchForTrenchCoatService(t1) == -1);
//    assert(s.searchForTrenchCoatService(t2) == 10);
//    try{
//        s.updateTrenchCoatService(t2, t2);
//        assert(false);
//    }
//    catch(std::invalid_argument& exc){
//        assert(true);
//    }
//    try{
//        s.updateTrenchCoatService(t1, t2);
//        assert(false);
//    }
//    catch(std::invalid_argument& exc){
//        assert(true);
//    }
//
//    TrenchCoat t3 = s.getTrenchCoatByPositionService(1);
//    try{
//        s.replaceTrenchCoatService(t2, t3);
//        assert(false);
//    }
//    catch(std::invalid_argument& exc){
//        assert(true);
//    }
//    s.replaceTrenchCoatService(t3, t1);
//    assert(s.getTrenchCoatByPositionService(1) == t1);
//    assert(s.searchForTrenchCoatService(t3) == -1);
//    try{
//        s.replaceTrenchCoatService(t3, t1);
//        assert(false);
//    }
//    catch(std::invalid_argument& exc){
//        assert(true);
//    }
//
//    // tests shopping cart
//    assert(s.getShoppingCart().size() == 0);
//    s.addToShoppingCart(t2);
//    std::vector<TrenchCoat> d = s.getShoppingCart();
//    assert(s.searchForTrenchCoatService(t2) == 0);
//    assert(s.getNumberOfItemsInShoppingCart() == 1);
//    assert(s.getTotalSum() == t2.getPrice());
//    s.addToShoppingCart(t1);
//    assert(s.getTotalSum() == t2.getPrice() + t1.getPrice());
//    assert(s.getNumberOfItemsInShoppingCart() == 2);
//    s.buyAll();
//    assert(s.getTotalSum() == 0);
//    assert(s.getNumberOfItemsInShoppingCart() == 0);
//
//    // test get all by size
//    std::vector<TrenchCoat> d2 = std::vector<TrenchCoat>();
//    d2 = s.getTrenchCoatsBySizeService(38);
//    assert(d2.size() == 4);
//    assert(d2[0].getSize() == 38);
//    TrenchCoat t4{ "black", "jghnfcbdxvc", 38, 25, 649 };
//    s.addTrenchCoatService(t4);
//    d2 = s.getTrenchCoatsBySizeService(38);
//    assert(d2.size() == 5);
//    assert(d2[4] == t4);
//}
//
//void Tests::testAll()
//{
//	testTrenchCoats();
//	testRepository();
//	testService();
//}
