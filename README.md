# AsyncLoadingScreenForUMG [![License](https://img.shields.io/github/license/Suuta/AsyncLoadingScreenForUMG.svg)](https://github.com/Suuta/AsyncLoadingScreenForUMG/blob/main/LICENCE.md)

<img src="/images/icon.jpg?raw=true" alt="icon" title="icon"  />

## 概要

AsyncLoadingScreenForUMG はUMGで非同期ローディング画面をするためのプラグインです。
サンプルプロジェクトでは以下の3パターンのローディング方法を用意しています。

* Slate (C++)
* UMG (BP → C++ 変換)
* UMG (ブループリント)



## 動作環境

UE4.23    ※4.27までビルドは成功するが求める挙動をしないため



## ビルド

* Game.uproject を右クリック、コンテキストメニューから Switch Unreal Engine versionで **4.23** を指定

* Game.sln を起動してビルドして実行

* Level/Start レベルを開き、**スタンドアローン**でプレイ

  

## カスタマイズ

UI/W_Start 内のパラメータを変更することでロードするレベルや、ローディングUMGを変更できますが、
**サンプルが軽量級レベルのため、ロードのテストになりません**。各自テスト用レベルを用意してください。
マーケットプレイスで重量級のレベルをダウンロードするのをオススメします。

https://www.unrealengine.com/marketplace/ja/product/infinity-blade-plain-lands



