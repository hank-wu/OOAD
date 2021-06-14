# Restaurant Management System
#### 2019/02 - 2019/06 オブジェクト指向分析設計
#### タームプロジェクト

# 目標
オブジェクト指向分析設計というソフトウェア開発でよく使われる方法を実際に使う。
解決したい問題からuse-caseを定義する。
問題に対するステム化の対象となる領域（問題領域; problem domain）を対象とし、分析して概念モデル(domain model) を作る。

概念モデルを原型としてソフトウェアを設計します。統一モデリング言語（UML）を使ってclass diagram, sequence diagram 作り、use-caseを満足するソフトウェアの設計図を作り出す。

開発はなるべくテスト駆動開発（TDD）で進め。

# Problem statement

人事支出を減らし、客様の注文を効率的に行うため、Restaurant Management Systemが必要です。このシステムがあれば、客様がレストランで店の席をチェックして、メニューを確認して注文する。そして、システムが注文情報を店員に送り、店員が全席の注文と把握する。オーナーはメニューをシステムで管理するとゆえに、このシステムは三つのキャラが使える。客様と店員の使うソフトウェアが接続必要です。


# Use Case Diagram
![Use Case Diagram](/image/Use_Case_Diagram.png)
# Use Case
![Use Case](/image/Use_Case.png)

# Demo figure
店員の画面

![emplyee Screenshot](/image/employeeScreenshot.png)

客様の画面

![clent Screenshot](/image/ClientScreenshot.png)
店員と客様のソフトウェアがsocketで繋がっている。


オーナの画面
![Boss Screenshot](/image/boss_screenshot.png)
# Domain model
![Domain_model](/image/Domain_model.png)
# Class Diagram
![class_diagram](/image/class_diagram.png)
# Logical Architecture
![logical_architecture](/image/logical_architecture.png)
# Sequence Diagram
UC1

![UC1](/image/uc01.png)


UC1のcomplete orderの操作の詳細
![UC1 complete order](/image/uc01-completeOrder.png)

# Source code of significant
![Get Receipe](/image/getReceipt.png)

source code:
https://github.com/hank-wu/OOAD/tree/jp_introduction/RMS

# Unit test result
![Run All test](/image/runAlltest.png)

![Example test code](/image/testSourceCode.png)

source code of unit test:
https://github.com/hank-wu/OOAD/tree/jp_introduction/RMS/test/rms_test


# Project information
![Project information](/image/project_image.png)
#


### プログラミング言語
C++
### フレームワーク
Qt5.12
### 環境
Win10
### ツール
sqlite db


# インストールと起動の手続き
Qt editorで実行