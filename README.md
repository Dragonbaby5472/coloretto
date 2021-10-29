# 變色龍
- ### 程式說明
    - 遊玩流程
        >先各發一張牌給每位玩家，之後玩家可以選擇抽牌或拿任意一排的牌，每排可以\
        >放三張牌，玩家拿走任何一排後就不能再抽牌或拿牌。當每個玩家都拿取一排後，\
        >一輪結束，玩家可再次抽排。若回合結束時排庫剩不到15張牌，遊戲結束。
    - 牌堆內容
        >共有七種顏色(藍、灰、粉紅、橘、黃、綠、棕)的顏色牌(變色龍)，每種顏色各9\
        >張，3張Joker(彩色變色龍)，10張+2。
    - 計分方法
        >同顏色牌一張1分，兩張3分，三張6分，四張10分，五張15分，六張以上皆算21分，\
        >Joker可當任何一種顏色的牌(在此程式會幫你自動分配到前三多且不超過六張的顏\
        >色)，前三多的顏色牌為正分，其他算負分，最後加上+2的分數即為最終得分。
-### 程式碼說明

    -變數
     ```cpp
    int card[76];	//牌堆中的排序
    int takeTimes = 0;   //算我們總共已從牌庫拿幾張牌
    char choose[100];	//存入使用者輸入一
    char ch[100];        //存入使用者輸入二
    int outputNumber[4][9];//存放要顯示的資料[玩家][顏色代碼]
    string nextCard;	//顯示下一張牌的字串
    /*要顯示在row上的字串*/
    string row1[3];
    string row2[3];
    string row3[3];
    string row4[4];
    /*用來確認每排有幾張卡牌*/
    int r1 = 0;
    int r2 = 0;
    int r3 = 0;
    int r4 = 0;
    int randN;	//random number
    /*用來幫電腦找他最多的顏色*/
    int big[3] = { 0,0,0 };
    int bigName[3] = { 0,1,2 };
    string bigNamestr[3];
    int row[4] = { 0,0,0,0 };
    int stop[4] = { 0,0,0,0 };
    char banRow[4] = { ' ',' ',' ',' ' };	//用來顯示哪排不能放牌，也用來流程控制
    /*流程控制用*/
    int temp = 0;
    int name = 0;
    ```
    
    -函數
    ``` cpp
    void putToRow();            //協助將卡牌放到指定排上
    bool checkInput(int, char); //檢查玩家輸入是否合法
    int howMany(int, int);      //計算各種類有幾張牌
    void cardOrder();         //將初始牌堆整理好
    int giveCard();           //從牌堆拿出一張牌
    int howMany(int, int);    //數每種牌共有幾張牌
    string checkcard(int);    //用來將牌的種類編碼翻譯成字串
    void inputA();            //處理玩家的第一個輸入
    bool checkInput(int, char);//檢查玩家的輸入是否有問題
    void draw();              //從牌庫抽一張牌，並翻譯成字串
    void inputB();            //玩家的第二個輸入
    void putToRow();          //照玩家的意思將牌放到指定排上，並檢查是否可以放
    void getRow(char, int);   //依玩家的意思拿取指定排，並檢查是否可以
    void frameForFour();      //設計的介面，方便玩家確認現在遊戲狀況
    void output(int, int);    //幫助我更改變數幫助我更改變數outputNumber[][]
    void computer(int);       //設計的電腦AI
    void computerDraw(int);   //幫助電腦抽牌
    void startCard();         //遊戲開始的抽牌
    int countScoreAI(int);    //結束計算分數的方法
    void endRound(int);       //判斷是否結束一輪或結束遊戲
    void people();            //控制玩家操作
    int main();               //開始讓玩家輪流玩
    ```
    
    - 電腦玩家設計
    >電腦會依據自己甚麼牌種較多去拿取較利於自己的牌，若沒有想要的牌就會抽牌，也會\
    >在規則強迫下去取牌。
    
    - ### 新手程式練習，大神勿噴
    
# **版權所有，翻印必究**
