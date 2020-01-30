class BoardTest : public Test {
private:
    void testIsWin() {
        Board b;
        b.move(0, 0);
        b.move(0, 1);
        b.move(1, 0);
        b.move(4, 5);
        b.move(5, 5);
        DO_CHECK(b.is_victory() == CONTINUE);
    }
    
    void testMove1() {
        Board b;
        b.move(0, 0);
        DO_CHECK(!b.canMove(0, 0));
    }
    
    void testMove2() {
        Board b;
        m.move(0, 0);
        DO_CHECK(b.canMove(1, 1));
    }
    
    // ...
    
public:
    void runAllTests() override {
        testIsWin();
        testMove1();
        testMove2();
        // ...
    }

    // ...
};