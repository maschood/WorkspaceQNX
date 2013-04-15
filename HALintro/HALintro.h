/*
 * HALintro.h
 */

#ifndef HALINTRO_H_
#define HALINTRO_H_

class HALintro {
private:
    static HALintro* instance;

    HALintro();
public:
    ~HALintro();

    static HALintro* getInstance();

    void lampeRotAn();
    void lampeRotAus();
};

#endif /* HALINTRO_H_ */
