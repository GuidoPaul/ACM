/*************************************************************************
  > File Name: Main.java
  > Author: Bslin
  > Mail: Baoshenglin1994@gmail.com
  > Created Time: 2014年08月07日 星期四 14时31分30秒
 ************************************************************************/

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigInteger;
import java.util.InputMismatchException;

public class Main {
	private static BigInteger[] f = new BigInteger[3000 + 10];

	public static void main(String args[]) throws FileNotFoundException {
		int cas, n;
		System.setIn(new FileInputStream("in.txt"));
		Scanner cin = new Scanner(System.in);
		cas = cin.nextInt();
		while (cas != 0) {
			cas --;
			n = cin.nextInt();
			for (int i = 1; i <= n; i++) {
				f[i] = cin.nextBigInteger();
			}
			BigInteger ans = BigInteger.ZERO;
			BigInteger yanghui = BigInteger.ONE;
			int flag = 0, m = 1;
			for (int i = n; i >= 1; i--) {
				BigInteger now = BigInteger.ONE;
				now = now.multiply(f[i]).multiply(yanghui);
				if (flag != 0) {
					now = now.multiply(BigInteger.valueOf(-1));
				}
				ans = ans.add(now);
				flag = 1 - flag;
				yanghui = (yanghui.multiply(BigInteger.valueOf(n-m))).divide(BigInteger.valueOf(m));
				m ++;
			}
			System.out.println(ans);
		}
	}
}

class Scanner {
	InputStream in;
	byte[] buf = new byte[1 << 10];
	int p, n;
	boolean[] isSpace = new boolean[128];

	Scanner(InputStream in) {
		this.in = in;
		isSpace[' '] = isSpace['\n'] = isSpace['\r'] = isSpace['\t'] = true;
	}

	int read() {
		if (n == -1)
			return -1;
		if (p >= n) {
			p = 0;
			try {
				n = in.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (n <= 0)
				return -1;
		}
		return buf[p++];
	}

	boolean hasNext() {
		int c = read();
		while (c >= 0 && isSpace[c])
			c = read();
		if (c == -1)
			return false;
		p--;
		return true;
	}

	String next() {
		if (!hasNext())
			throw new InputMismatchException();
		StringBuilder sb = new StringBuilder();
		int c = read();
		while (c >= 0 && !isSpace[c]) {
			sb.append((char) c);
			c = read();
		}
		return sb.toString();
	}

	int nextInt() {
		if (!hasNext())
			throw new InputMismatchException();
		int c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (c >= 0 && !isSpace[c]);
		return res * sgn;
	}

	long nextLong() {
		if (!hasNext())
			throw new InputMismatchException();
		int c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (c >= 0 && !isSpace[c]);
		return res * sgn;
	}

	double nextDouble() {
		return Double.parseDouble(next());
	}

	BigInteger nextBigInteger() {
		String str = next();
		return new BigInteger(str);
	}
}
