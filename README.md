<h1 align="center">
 42Cursus ft_printf
</h1>

<p align="center">
  <img src="ft_printfe.png" />
</p>

<h2 align="center">
  Key Points
</h2>

### 可変長引数
通常の関数宣言では引数は型一致した一つの値しか受け取ることができない</br>
可変長引数関数は異なる個数の引数を用いて呼び出すことができる</br>
下記プロトタイプ宣言</br>

```c
#include <stdarg.h>
void func(char *fmt, ...);
```

引数リストの最後かつ少なくとも一つの名前付き引数の後である必要がある</br>
注意点として、呼び出し側は引数の型や個数を知ることができないので、適切な処理が求められる</br>
不一致な型へ代入しようとした際は未定義動作である</br>
下記man抜粋

| マクロ             | 説明                                          |
|-----------------|-----------------------------------------------|
| va_start(ap, last) | 必ず最初に呼び出さなければならない</br>これは`ap`を初期化し、`va_arg()`と`va_end()`で用いることができるようにする</br>`last`は引き数リストのうち、可変な部分の直前に置かれる引き数の名前である</br> この引き数はレジスタ変数や関数、配列として宣言できない|
| va_arg(ap, type) | 呼び出し時に指定された引き数のうち、 次の位置にあるものを指定した`type`の値として取得する</br>`va_arg()`を呼び出すごとに`ap`は変更され、次回呼び出しの際に次の引数を返すようになる |
| va_end() | `va_start()`が実行される毎に、同じ関数内で対応する`va_end()`が実行されなければならない</br>`va_end()`後の引数ポインタの値は不定値となる</br>`va_end()`後`va_start()`を再度実行することも可能であり、その際は引数リストの最初から再度アクセスが可能</br> |
| va_copy(dest,src) | 可変長引き数リスト`src`を`dest`にコピーする</br>新規に`va_list型`の変数を定義し第一引数にコピー先、第二引数にコピーもとを配置する</br>`va_copy()`が実行されるごとに、対応する`va_end()`を同じ関数内で実行しなければならない |

サンプルコード
```c
#include <stdarg.h>
#include <stdio.h>

void	nbr_print(char *str, ...)
{
	va_list	args;

	va_start(args, str);
	printf("▽--result--▽\n")
	printf("%d\n", va_arg(args, int));
	printf("%d\n", va_arg(args, int));
	printf("%d\n", va_arg(args, int));
	printf("%d\n", va_arg(args, int)); /* 未定義　*/
	va_end(args);
}

int	main(void)
{
	nbr_print("start", 1, 2, 3);
}
```
▽実行結果▽
```shell
▽--result--▽
1
2
3
-231522224 # 未定義動作
```
