/*************************************************************************
  > File Name: poj3101.java
  > Author: Bslin
  > Mail: Baoshenglin1994@gmail.com
  > Created Time: 2014年08月16日 星期六 10时24分29秒
 ************************************************************************/
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigInteger;
import java.util.InputMismatchException;

/**
 *  * @author Bslin
 *   * @mail Baoshenglin1994@gmail.com
 *    * @date 2014年8月15日下午5:43:04
 *     */
public class Main {

	public static final int N = 10000;

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("in"));
		Scanner cin = new Scanner(System.in);
		int n;
		int[] t = new int[N];
		int[] p = new int[N];
		while (cin.hasNext()) {
			n = cin.nextInt();
			for (int i = 0; i < n; i++) {
				t[i] = cin.nextInt();
			}
			int fz, fm, gg, fmm = 0;
			for (int i = 1; i < n; i++) {
				if (t[i] != t[0]) {
					fz = t[i] * t[0];
					fm = Math.abs(t[i] - t[0]) << 1;
					gg = gcd(fz, fm);
					fz = fz / gg;
					fm = fm / gg;

					fmm = gcd(fmm, fm);

					for (int j = 2; fz > 1; j++) {
						if (fz % j == 0) {
							int k = 0;
							while (fz % j == 0) {
								fz /= j;
								k++;

							}
							if (k > p[j])
								p[j] = k;

						}

					}

				}

			}
			BigInteger fzz = BigInteger.ONE;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < p[i]; j++) {
					fzz = fzz.
						multiply(BigInteger.valueOf(i));
				}
			}
			System.out.println(fzz + " " + fmm);
		}
	}

	private static int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);

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
