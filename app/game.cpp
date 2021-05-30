#include "game.h"

Game::Game(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    ball = new Ball();
    panel = new Panel();
    state = GameState::playing;
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}

void Game::update() {
    if(state != GameState::playing) timer->stop();

    QPoint ballPos = ball->getPos();
    QPoint panelPos = panel->getPos();
    QSize ballSize = ball->getSize();
    QSize panelSize = panel->getSize();

    if(!collision.checkInside(QRect(QPoint(-10, -10), fieldSize + QSize(20, 20)), ballPos, ballSize)) {
        state = GameState::lose;
        emit loseGame();
    }

    if(collision.checkCollison(ballPos, ballSize, panelPos, panelSize)) {
        ball->goUp();
        ball->randomizeX();
    }

    if(collision.checkCollisonRect(topWall, ballPos, ballSize)) {
        ball->goDown();
    }

    if(collision.checkCollisonRect(leftWall, ballPos, ballSize)) {
        ball->goRight();
    }

    if(collision.checkCollisonRect(rightWall, ballPos, ballSize)) {
        ball->goLeft();
    }

    int brokenCount = 0;
    for(int i = 0; i < blocks.length(); i++) {
        if(blocks[i].first == true) {
            if(collision.checkCollisonRect(blocks[i].second, ballPos, ballSize)) {
                blocks[i].first = false;
                ball->goDown();
                brokenCount++;
            }
        } else {
            brokenCount++;
        }
    }

    if(brokenCount == blocks.length()) {
        state = GameState::win;
        emit winGame();
    }

    ball->update();
    ballPos = ball->getPos();
    QList<bool> blocksStatus;

    for(int i = 0; i < blocks.length(); i++) {
        blocksStatus.push_back(blocks[i].first);
    }

    emit updateGame(ballPos.x(), ballPos.y(), blocksStatus);
}

void Game::setFieldSize(int w, int h) {
    fieldSize = QSize(w, h);
    topWall = QRect(QPoint(0, 0), QSize(w, 1));
    rightWall = QRect(QPoint(0, 0), QSize(1, h));
    leftWall = QRect(QPoint(w, 0), QSize(1, h));
}

void Game::setPanelSize(int w, int h) {
    panel->setSize(QSize(w, h));
}

void Game::setPanelPos(int x, int y) {
    panel->setPos(QPoint(x, y));
}

void Game::setBallSize(int w, int h) {
    ball->setSize(QSize(w, h));
}

void Game::setBallPos(int x, int y) {
    ball->setPos(QPoint(x, y));
}

bool Game::setBlocks(QList<int> posX, QList<int> posY, int w, int h) {
    blocks.clear();

    if(posX.length() != posY.length()) return false;

    for(int i = 0; i < posX.length(); i++) {
        blocks.push_back(QPair<bool, QRect>(true, QRect(posX[i], posY[i], w, h)));
    }

    return true;
}

void Game::resetBlocks() {
    for(int i = 0; i < blocks.length(); i++) {
        blocks[i].first = true;
    }
}

void Game::newGame() {
    emit resetField();

    state = GameState::playing;
    ball->resetAcc();
    resetBlocks();

    if(timer->isActive()) {
        timer->stop();
    }

    timer->start(16);
}
