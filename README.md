# 🔥🔥🔥Embedded_Interview_T4
-------------------------------------------------------------
## 🧾Documents
-------------------------------------------------------------

### 💊 Bitwise operation

<details>

<summary> 🔸 Bitwise operators</summary>
   
### **AND**   
 
> - Tương tự phép nhân
> - Ký hiệu: **&**
   
|  A  |  B  | A & B |
| --- | --- | ----- |
|  0  |  0  |   0   |
|  0  |  1  |   0   |
|  1  |  0  |   0   |
|  1  |  1  |   1   |

> Dùng toán tử AND để kiểm tra tính chẵn lẽ của số nhị phân dễ dàng hoặc xóa các bit trong một thanh ghi.
> ```ruby
> 0110 (số thập phân 6)
> AND 1101 (số thập phân 13)  // xóa đi bit thứ 2
> = 0100 (số thập phân 4)
> ```

### **OR**   
 
> - Tương tự phép cộng
> - Ký hiệu: **|**
   
|  A  |  B  | A or B |
| --- | --- | ----- |
|  0  |  0  |   0   |
|  0  |  1  |   1   |
|  1  |  0  |   1   |
|  1  |  1  |   1   |

> - Phép toán thao tác bit OR có thể được sử dụng để thiết đặt bit được chọn thành 1. Ví dụ: Nó có thể được sử dụng để bật (set) một bit (hoặc cờ) trong thanh ghi, trong đó mỗi bit đại diện cho một trạng thái trong phép logic đúng sai (boolean). Vì thế, 0010 (số 2 thập phân) có thể được xem là một bộ 4 cờ, trong đó cờ thứ nhất, thứ ba và thứ tư là trống (0)  và cờ thứ hai được bật (1). Cờ thứ tư có thể được bật bằng cách thực hiện phép toán thao tác bit OR giữa giá trị này và một dãy bit với duy nhất bộ bit thứ 4:
> ```ruby
> 0010 (số thập phân 2)
> OR 1000 (số thập phân 8)  //Bật bit thứ 4 lên
> 1010 (số thập phân 10)
> ```
> - Kỹ thuật này là một cách hiệu quả để lưu trữ một số trong những giá trị phép toán logic đúng sai (boolean) sử dụng ít bộ nhớ nhất có thể.
> - Khi làm việc với các máy không có nhiều không gian bộ nhớ trống, các lập trình viên thường áp dụng kĩ thuật trên. Lúc đó, thay vì khai báo tám biến kiểu bool (C++) độc lập, người ta sử dụng từng bit riêng lẻ của một byte để biểu diễn giá trị cho tám biến đó.`

### **XOR**   
 
> - Kết quả ở mỗi vị trí là 1 chỉ khi bit đầu tiên là 1 hoặc nếu chỉ khi bit thứ hai là 1, nhưng sẽ là 0 nếu cả hai là 0 hoặc cả hai là 1. Ở đây ta thực hiện phép so sánh hai bit, kết quả là 1 nếu hai bit khác nhau và là 0 nếu hai bit giống nhau.
> - Ký hiệu: **^**
   
|  A  |  B  | A ^ B |
| --- | --- | ----- |
|  0  |  0  |   0   |
|  0  |  1  |   1   |
|  1  |  0  |   1   |
|  1  |  1  |   0   |   
   
> Phép toán thao tác bit XOR có thể được sử dụng để đảo ngược các bit được lựa chọn trong thanh ghi (còn được gọi là bật (set) hoặc lật (flip)). Bất kỳ bit nào được bật bằng cách thực hiện phép toán thao tác bit XOR nó với 1.
> ```ruby
> 0010 (số thập phân 2)
> XOR 1010 (số thập phân 10)  // Kích hoạt trạng thái bit 2 và 4
> = 1000 (số thập phân 8)  
> ```

### **NOT**

>  - Là toán tử một ngôi thực hiện phủ định luận lý trên từng bit, tạo thành bù 1 (one’s complement) của giá trị nhị phân cho trước
>  - Ký hiệu : **~**
   
|  A  |  ~A | 
| --- | --- | 
|  0  |  1  | 
|  1  |  0  |  
    
</details>

<details>

<summary> 🔸 Bitwise operators</summary>

Các phép dịch chuyển bit đôi khi được xem là các phép toán thao tác bit, bởi vì chúng sẽ xem một giá trị dưới dạng một dãy bit hơn là dưới dạng số lượng số (numerial quantity). Trong các phép toán này, các chữ số sẽ được di chuyển, hoặc dịch chuyển, sang trái hoặc phải. Các thanh ghi trong vi xử lý máy tính có độ dài cố định, vì vậy một vài bit sẽ bị "dịch chuyển ra ngoài" thanh ghi ở một đầu, trong khi đó thì một lượng bit tương ứng sẽ được "dịch chuyển vào" ở đầu còn lại; sự khác biệt ở các phép toán dịch chuyển bit nằm ở chỗ cách chúng xác định giá trị của các bit được dịch chuyển vào.   
   
### **Dịch chuyển số học**   
   
> Trong dịch chuyển số học, các bit được dịch chuyển ra khỏi đầu hoặc đuôi sẽ bị loại bỏ. Trong phép dịch chuyển số học về bên trái, các số 0 được dịch chuyển vào bên phải; trong phép dịch chuyển số học bên phải, bit thể hiện dấu được thêm vào bên trái, do đó dấu của số được giữ nguyên.   

```ruby
   
00010111 (số thập phân +23) Dịch chuyển trái
= 00101110 (số thập phân +46)
   
10010111 (số thập phân -105) Dịch chuyển phải
= 11001011 (số thập phân -53)
   
```
![Rotate_right_arithmetically](https://github.com/SSamlu/Embedded-interview-Learning/assets/41613967/5c07a6a0-2636-4f62-85f0-f9520abaae80)        

### **Dịch chuyển luận lý** 

> - Trong dịch chuyển luận lý, các số 0 sẽ được dịch chuyển vào để thay thế các bit bị loại bỏ. Do đó dịch chuyển luận lý và dịch chuyển số học bên trái là hoàn toàn giống nhau.
> - Tuy nhiên, dịch chuyển luận lý thêm giá trị 0 vào vị trí bit quan trọng nhất, thay vì sao chép bit mang dấu, điều này khá lý tưởng cho các số nhị phân không dấu, trong khi phép dịch chuyển số học sang phải thì lại lý tưởng cho các số nhị phân bù 2 có dấu.
![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/65484fc0-d8b1-4b78-bfbd-a4690e21ff30)

### **Quay không nhớ**

> Một dạng khác của dịch chuyển được gọi là dịch chuyển vòng hay quay bit. Với phép toán này, các bit được xoay giống như là hai đầu của thanh ghi được gộp lại với nhau. Những giá trị được dịch chuyển vào ở bên phải trong một lần dịch chuyển trái chính là bất kỳ giá trị nào đã được dịch chuyển ra ở bên trái, và ngược lại. Thao tác này hữu ích nếu xảy ra yêu cầu giữ lại toàn bộ bit hiện thời, và thường được sử dụng trong mật mã học kỹ thuật số.

![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/3b1f04d5-6009-4486-9850-c6478276214b)

### **Quay có nhớ**

> - Quay có nhớ tương tự với phép quay không nhớ, nhưng hai đầu của thanh ghi được tách ra bởi cờ nhớ (carry flag). Bit được dịch chuyển vào (ở bất kỳ đầu nào) là giá trị cũ của cờ nhớ, và bit được dịch chuyển ra (ở đầu còn lại) trở thành giá trị mới của cờ nhớ.
> - Một phép quay có nhớ có thể mô phỏng một phép quay luận lý hoặc số học của một vị trí bằng cách thiết lập cờ nhớ trước tiên. Ví dụ, nếu cờ nhớ mang giá trị 0, thì x XOAY-PHẢI-CÓ-NHỚ-MỘT-LẦN là phép dịch chuyển luận lý sang phải, và nếu cờ nhớ giữ giá trị của bản sao chép của bit chứa dấu, thì x XOAY-PHẢI-CÓ-NHỚ-MỘT-LẦNlà phép dịch chuyển số học sang phải. Vì lý do này, một số vi điều khiển như các PIC tầm thấp chỉ có xoay và xoay có nhớ, mà không cần đến các cấu trúc dịch chuyển số học và luận lý.

### **👉 Dịch chuyển trong C, C++, C# và Python**

Trong các ngôn ngữ dựa trên C, các toán tử dịch chuyển trái và phải lần lượt là << và >>. Số lượng cần dịch chuyển được cung cấp ở đối số thứ hai của toán tử dịch chuyển. 

> Ví dụ:
> ```ruby
> x = y << 2;
> ```
> gán cho x kết quả của phép dịch chuyển y sang trái 2 bit, tương đương với phép nhân với 4.

Trong ngôn ngữ C, kết quả của việc dịch chuyển sang phải một giá trị âm là xác định, và giá trị của phép dịch chuyển sang trái của giá trị chứa dấu là không xác định nếu kết quả không được thể hiện dưới dạng của kết quả. Trong C#, phép dịch chuyển sang phải là một phép dịch chuyển số học khi mà toán hạng là biến kiểu int hoặc long. Nếu toán hạng đầu tiên thuộc kiểu uint hoặc ulong, phép dịch chuyển sang phải là phép dịch chuyển luận lý.

</details> 

##

### 💊 C

<details>

<summary>** Macro, Inline and Function</summary>

###  **Macro**
   
> - được xử lý (được diễn ra) bởi tiền xử lý (preprocessor)
> - Thay thế đoạn code được khai báo macro vào bất cứ chỗ nào xuất hiện macro đó
>>   ```ruby
>>   VD: #define SUM(a,b)     (a+b)
>>   ```
> - Preprocessor khi gặp bất kỳ lời gọi SUM(first+last) nào thì thay ngay bằng (first+last)

### **Inline**
   
> - Được xử lý bởi compiler
> - Được khai báo với từ khóa inline
> - Khi compiler thấy bất kỳ chỗ nào xuất hiện inline function, nó sẽ thay thế chỗ đó bởi định nghĩa của hàm đã được compile tương ứng. –> Phần được thay thế không phải code mà là đoạn code đã được compile
   
### **Function**
   
> - Hàm bình thường, khi thấy hàm được gọi, chương trình lưu đia chỉ hiện tại vào ***Stack Pointer***, sau đó chỏ con trỏ PC đến phân vùng nhớ của hàm được gọi. Thực thi câu lệnh của hàm được gọi, lấy kết quả lưu vào ***Stack***. Sau đó nó quay lại vào ***Stack Pointer***, lấy địa chỉ đó ra và tiếp tục chạy tiếp chương trình.
> - Như có thể thấy, các này khiến chương trình tốn thời gian hơn là chỉ cần thay thế đoạn code đã được compile (cách của inline function).
   
### 💹 Compare
> - Macro đơn giản là chỉ thay thế đoạn code macro vào chỗ được gọi trước khi được biên dịch
> - Inline thay thế đoạn mã code đã được biên dịch vào chỗ được gọi
> - Hàm bình thường phải tạo một function call, lưu địa chỉ trước khi gọi hàm vào stack sau đó mới thực hiện hàm và sau cùng là quay trở về địa chỉ trên stack trước khi gọi hàm và thực hiện tiếp chương trình
> - Macro khiến code trở nên dài hơn rất nhiều so với bình thường nhưng thời gian chạy nhanh.
> - Hàm inline cũng khiến code dài hơn, tuy nhiên nó làm giảm thời gian chạy chương trình
> - Hàm bình thường sẽ phải gọi function call nên tốn thời gian hơn inline function nhưng code ngắn gọn hơn.

</details>   

<details>

<summary>🔸 Static</summary>
   
### Static cục bộ
   
> Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.   
   
### Stactic toàn cục   
> Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được. 
   
</details>   

<details>

<summary>🔸 Struct and Union</summary>  

> Về mặt ý nghĩa, struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau:
>> * Struct: 
>>>>    - lấy dịa chỉ đầu tiên của member làm địa chỉ của struct.
>>>>    - kích thước của nó là tổng của các member và struct padding(bộ nhớ đệm)
>>>>    - Dữ liệu của các member trong struct được lưu trữ trong các vùng nhớ khác nhau(Địa chỉ riêng biệt).
>>>>    - kích thước mỗi lần quét được tính dược theo member lớn nhất
>>>>          + mỗi lượt quét nó sẽ kiểm tra xem phía trước nó còn bộ nhớ đệm không nếu còn thì tiếp tục thêm vào bộ nhớ cón thừa bộ nhớ đệm, nếu bộ nhớ đệm nhỏ hơn kích thước member thì sẽ tạo một lượt quét khác.
>> * Union : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác:
>>>>    - lấy địa chỉ đầu tiên của member làm địa chỉ của Union
>>>>    - Kích thước union là kích thước của member lớn nhất
>>>>    - Dữ liệu của các member dùng chung bộ nhớ
>>>>>>      + Do việc dùng chung vùng nhớ khi truyền data vào member thì nó sẽ ghi đè lên member trước của nó.

</details>     

<details>

<summary>🔸 Compiler</summary>
   
> Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:
>> - 	Giai đoàn tiền xử lý (Pre-processor)
>> -	Giai đoạn dịch NNBC sang Asembly (Compiler)
>> - 	Giai đoạn dịch asembly sang ngôn ngữ máy (Asember)
>> -	Giai đoạn liên kết (Linker)
   
   ![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/52d3dd8f-a648-47ed-a00c-5418478a37f0)
   
1. **Giai đoạn tiền xử lý – Preprocessor**
   
> - từ các file .c/cpp, h/hpp, nó sẽ trở thành file lớn duy nhất main.i thông qua tiền xử lý(preprocessor). Giai đoạn này sẽ thực hiện:
>>   + Nhận mã nguồn
>>   + Xóa bỏ tất cả chú thích, comments của chương trình
>>   + xử lý những file include bằng các import các thư viện của nó vào file main
>>   + marco: được xử lý (được diễn ra) bởi tiền xử lý
>>>>	  1. sẽ bị xóa.
>>>>	  2. thay thế những đoạn code được định nghĩa bằng macro(bằng đoạn code macro được định nghĩa) vào chương trình
>>>>>>         + nó chỉ đơn giản là thay những đoạn macro trước khi biên dịch. 
>>>>	  3. thay thế những tên marco trong chương trình bằng giá trị của marco đó thì nó sẽ làm tăng kích thước của chương trình.
>>>>	  4. tốc độ thực thi của marco sẽ nhanh (hơn function), nhưng kích thước nó sẽ lớn (hơn function), do có sẽ thay các macro trong chương trình bằng đoạn code.
>>>>	  5. không phải là kiểu dữ liệu
>>>>    6. nó không có địa chỉ riêng biệt trong bộ nhớ
>>   + Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý
> - quá trình này sẽ tạo ra file .i
> - Ví dụ: chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.
   
2. **Công đoạn dịch Ngôn Ngữ Bậc Cao sang Assembly**
  
> - Phân tích cú pháp (syntax) của mã nguồn NNBC.
> - Chuyển chúng sang ngôn ngữ bậc thấp assembly code, gần với tập lệnh của VXL.
>>   + Quá trình chạy funtion:(hàm không lưu trọng bộ nhớ stack chỉ có tham số và biến của hàm lưu thôi)
>>>>    1. khi hàm được gọi (thay đổi địa chỉ đột ngột) thì (nó sẽ lưu địa chỉ hiện tại đang chạy vào stack point) chương trình đang chạy sẽ dừng ở vị trí trước khi vào hàm được gọi, nó lấy địa chỉ trước hàm được gọi, sẽ lưu vào `stack point`, program counter sẽ trỏ đến địa chỉ của hàm được gọi, khi chạy xong và lấy giá trị trả về thì nó sẽ vào stackpointer để lấy địa chỉ trước khi vào function được gọi để tiếp trục chạy tiếp
>>>>>>	   + program counter : là để đếm,...
>>>>	  2. mỗi lần gọi làm thì đại chỉ của hàm sẽ khác nhau, do được lưu trong phân vùng nhớ stack, nên khi kết chương trình thì bộ nhớ sẽ được giải phóng.
>>>>	  3. kích thước bộ nhớ của funtion (cố định) ngắn hơn macro, nhưng tốc độ chậm hơn (do khi gọi hàm nó sẽ gọi hàm, lưu vào stackpointer...)

3. **Công đoạn dịch Assembly**
   
> - Biên dịch chương trình sang ngôn ngữ máy là binary code
> - quá trình assembler tạo ra các obj file từ assembly code, quá trình này sẽ tạo ra file .o
   
4. **Giai đoạn Linker**
   
> - Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất.
> - Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.
> - Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.
> - Kết thúc quá trình tất cả các đối tượng được liên kết lại với nhau thành một chương trình có thể thực thi được (executable hay .exe) thống nhất.
   
</details>   

<details>

<summary>🔸 Pointer</summary>    

### **Tổng quát**

> Bộ nhớ RAM chứa rất nhiều ô nhớ, mỗi ô nhớ có kích thước 1 byte.
> Mỗi ô nhớ có địa chỉ duy nhất và địa chỉ này được đánh số từ 0 trở đi. Nếu CPU 32 bit thì có 2^32 địa chỉ có thể đánh cho các ô nhớ trong RAM.
   
![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/78254da9-8f27-4c57-b858-21ac9ae3b21d)

> Khi khai báo biến, trình biên dịch dành riêng một vùng nhớ với địa chỉ duy nhất để lưu biến. Trình biên dịch có nhiệm vụ liên kết địa chỉ ô nhớ đó với tên biến. Khi gọi tên biến, nó sẽ truy xuất tự động đến ô nhớ đã liên kết với tên biến để lấy dữ liệu. Các bạn phải luôn phân biệt giữa địa chỉ bộ nhớ và dữ liệu được lưu trong đó.
   
![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/083070ea-72f1-4c19-9d46-c888e2e7e642)
 
> Địa chỉ của biến bản chất cũng là một con số thường được biểu diễn ở hệ cơ số 16. Ta có thể sử dụng con trỏ (pointer) để lưu địa chỉ của các biến.
   
### **Con trỏ là gì**
   
> Trong ngôn ngữ C/C++, con trỏ (pointer) là những biến lưu trữ địa chỉ bộ nhớ của những biến khác.
   
![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/de60652b-39ca-484f-a139-58c742ae50f3)
 
> Trong hình trên, biến var lưu giá trị 5 có địa chỉ là 0x61ff08. Biến pointVar là biến con trỏ, lưu địa chỉ của biến var (trỏ đến vùng nhớ của biến var), tức là nó lưu giá trị 0x61ff08.
   
🔹 **Con trỏ NULL**
> Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. Tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.
   
```ruby
int *p2;//con trỏ chưa khởi tạo, vẫn trỏ đến một vùng nhớ nào đó không xác định
int *p3 = NULL;//con trỏ null không trỏ đến vùng nhớ nào
```   
🔹 **Kích thước của con trỏ**
   
Ví dụ các khai báo con trỏ sau:

```ruby   
char *p1;
int *p2;
float *p3;
double *p4;
```
   
> ❗ Con trỏ chỉ lưu địa chỉ nên kích thước của mọi con trỏ là ***như nhau***. Kích thước này phụ thuộc vào môi trường hệ thống máy tính:
>> - Môi trường Windows 32 bit: 4 bytes
>> - Môi trường Windows 64 bit: 8 bytes
   
🔹 **Một số lưu ý khi sử dụng con trỏ**
 
Khi khởi tạo con trỏ NULL -> Chữ NULL phải viết hoa, viết thường null sẽ bị lỗi

```ruby   
int *p1 = NULL;//đúng
int *p2 = null;//lỗi
```
   
Không nên sử dụng con trỏ khi chưa được khởi tạo. Kết quả tính toán có thể sẽ phát sinh những lỗi không lường trước được nếu chưa khởi tạo con trỏ.
Sử dụng biến con trỏ sai cách.
   
</details>   
   
##

### 💊 C++      
<details>

<summary>🔸 Class</summary>
   
### Khái niệm
> Class hay lớp là một mô tả trừu tượng **(abstract)** của nhóm các đối tượng **(object)** có cùng bản chất, ngược lại mỗi một đối tượng là một thể hiện cụ thể **(instance)** cho những mô tả trừu tượng đó. Một class trong C++ sẽ có các đặc điểm sau:  \
> - Là kiểu dữ liệu do người dụng tự định nghĩa, nó là một object.
> - Một class bao gồm các thành phần dữ liệu (thuộc tính hay property) và các phương thức (hàm thành phần hay method).
> - Class thực chất là một kiểu dữ liệu do người lập trình định nghĩa.
> - Trong C++, từ khóa class sẽ chỉ điểm bắt đầu của một class sẽ được cài đặt.
 
### Khai báo class và sử dụng class
   
```cpp
class Person {
public:
string firstName; // property
string lastName; // property
int age; // property
void fullname() { // method
cout << firstName << ' ' << lastName;
}
}
```
   
 ### Access modifiers & properties declaration
   
> ***Access modifier*** là phạm vi truy cập của các thuộc tính và phương thức sẽ được khai báo bên dưới nó. Có 3 phạm vi truy cập trong C++ là **public**, **private** và **protected**
> - Các thuộc tính và phương thức khai báo public thì có thể được truy cập trực tiếp thông qua instance của class đó. Các thuộc tính nên khai báo là public nếu bạn không có ràng buộc điều kiện trước khi gán (người dùng có thể  thoải mái gán giá trị) hoặc bạn không cần xử lý trước khi trả về giá trị thuộc tính.
> - Các thuộc tính private thường được sử dụng khi bạn không mong muốn người khác có thể tùy ý gán giá trị hoặc là bạn muốn xử lý trước khi trả về giá trị.
> - Đối với protected, các phương thức và thuộc tính chỉ có thể truy cập qua các class kế thừa nó hoặc chính nó.

### Method declaration
   
   > Phương thức cũng giống như một hàm bình thường. Nó có thể có hoặc không có tham số, không trả về giá trị và thậm chí là override hàm.
     Đối với phương thức thì có **hai cách** định nghĩa thi hành: định nghĩa thi hành trong lúc định nghĩa class và định nghĩa thi hành bên ngoài class.
 
   👉 **Định nghĩa thi hành bên trong class:**
```ruby
class Animal {
 public:
 string sound;
 void makeNoise() {
 cout << sound;
 }
};
```
   
   👉 **Định nghĩa thi hành bên ngoài class:**
```ruby
class Animal {
 public:
 string sound;
 void makeNoise();
};
void Animal::makeNoise() {
 cout << sound;
}
```

   👉 **Tham số truyền vào phương thức:**  
- Cách 1: Dặt tên trùng với thuộc tính Class bằng cách kết hợp toán tử :: và con trỏ _this_\
- Cách 2: Đặt tên khác với thuộc tính ( thường thêm dấu "_" trước tên tham số giống thuộc tính private
   
🔹 ***Con trỏ this*** : đề cập đến thể hiện hay instance của class đó, thông qua con trỏ this ta có thể truy cập đến các thuộc tính và phương thức.
   
🔹 ***Toán tử phạm vi*** : dùng để xác định phương thức hoặc thuộc tính được gọi từ Class nào.
   
### Constructor
> Constructor hay hàm dựng là một hàm đặc biệt, nó sẽ được gọi ngay khi chúng ta khởi tạo một object. Công dụng chính là khởi gán các thuộc tính
   
### Static member
> Static member hay thành viên tĩnh trong class C++ cũng tương tự như với static variable (biến tĩnh) trong function. Đối với function, sau khi thực hiện xong khối lệnh và thoát thì biến tĩnh vẫn sẽ không mất đi. Đối với class, thành viên tĩnh sẽ là thuộc tính dùng chung cho tất cả các đối tượng của class đó, cho dù là không có đối tượng nào tồn tại. Tức là bạn có thể khai báo nhiều object, mỗi object các thuộc tính của nó đều khác nhau nhưng riêng static thì chỉ có một và static member tồn tại trong suốt chương trình cho dù có hay không có object nào của nó hay nói ngắn gọn là dùng chung một biến static.

</details>

<details>

<summary>🔸 OOP</summary>

### Khái niệm
> OOP Object - Oriented Programming là cách tư duy mới tiếp cận hướng đối tượng để giải quyết các vấn đề bằng máy tính. Là một mô hình dựa trên khái niệm về Class và Object. Nó được sử dụng để tách 1 chương trình thành các phần đơn giản hơn, có thể tái sử dụng.

### Các đặc tính của lập trình hướng đối tượng
> Có 4 đặc tính: Kế thừa, Trừu tượng, Đa hình và Đóng gói

👉 **Tính kế thừa / Inheritance**
- Có 3 loại kế thừa : public, private và protected
   
   > Có nghĩa là một Class có thể kế thừa lại Class trước đó. Class kế thừa được gọi là Class con hay còn gọi là _subclass_. Class được kế thừa gọi là class cha hay còn gọi là _superclass_. Ngoài ra còn có thể mở rộng thêm các thành phần kế thừa và bổ sung thêm các thành phần mới.
   
👉 **Tính trừu tượng / Abstraction**
- Chỉ cần biết kết quả chứ không quan tâm cách làm
   > Là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông tin cần xử lý. Điều đó có nghĩa, bạn có thể xử lý một đối tượng bằng cách gọi tên một phương thức và thu về kết quả xử lý, mà không cần biết làm cách nào đối tượng đó được các thao tác trong class.

👉 **Tính đa hình / Polymorphism**
- Có thể đạt được đa hình theo kiểu ghi đè phương thức (Method Overriding) hoặc nạp chồng phương thức ( Method Overloading)
   > Là một khả năng mà một phương thức trong class có thể đưa ra các kết quả hoàn toàn khác nhau, tùy thuộc vào dữ liệu được xử lý.
   
👉 **Tính đóng gói / Encapsulation**
- Mỗi thuộc tính sẽ có phạm vi truy cập hay còn gọi là access modifier -> Private
   > Có ý nghĩa không cho phép người sử dụng các đối tượng thay đổi trạng thái nội tại của một đối tượng, mà chỉ có phương thức nội tại của đối tượng có thể thay đổi chính nó. Điều đó có nghĩa, dữ liệu và thông tin sẽ được đóng gói lại, giúp các tác động bên ngoài một đối tượng không thể làm thay đổi đối tượng đó, nên sẽ đảm bảo tính toàn vẹn của đối tượng, cũng như giúp dấu đi các dữ liệu thông tin cần được che giấu.

</details>

<details>

<summary>🔸 Namespacce and Templete</summary>
   
### Namespace
   > Namespace là từ khóa trong C++ được sử dụng để định nghĩa một phạm vi nhằm mục đích phân biệt các hàm, lớp, biến, ... cùng tên trong các thư viện khác nhau. Thông thưognf ta hay dùng namespace "std" trong thư viện iostream

### Templete
   > Là một từ khóa trong C++, và là một kiểu dữ liệu trừu tượng tổng quát hóa cho các kiểu dữ liệu int, float, double, bool...
     Template trong C++ có **2 loại** đó là _ function template_ & _class template_.
     Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu dữ liệu khác nhau.

</details>

<details>

<summary>🔸Virtual</summary>
   
> Là một hàm thành viên trong lớp cơ sở mà lớp dẫn xuất khi kế thừa cần ***phải định nghĩa lại***.
> Hàm ảo được sử dụng trong lớp cơ sở khi cần đảm bảo hàm ảo đó sẽ được định  nghĩa lại trong lớp dẫn xuất. Việc này rất cần thiết trong trường hợp con trỏ có  kiểu là lớp cơ sở trỏ đến _đối tượng của lớp dẫn xuất_ ( hàm dẫn xuất được coi là khốp với lớp cơ sở nếu có cùng tên, loại tham số 'cho dù có là const' và kiểu trả về của hàm trong lớpcơ sở. Các hàm như vậy được gọi là ghi đè (Overiding).
> Hàm ảo chỉ khác hàm thành phần thông thường khi được gọi từ một con trỏ. Sử  dụng hàm ảo khi muốn con trỏ đang trỏ tới đối tượng của lớp nào thì hàm thành phần của lớp đó sẽ được gọi mà không xem xét đến kiểu của con trỏ.
   
❗**Lưu ý**: Con trỏ của lớp cơ sở có thể chứa địa chỉ của đối tượng thuộc lớp dẫn xuất, nhưng ngược lại thì không được.
   
</details>

<details>

<summary>🔸Vector</summary>
   
> Giống như là mảng (array), vector trong C++ là một đối tượng dùng để chứa các đối  tượng khác, và các đối tượng được chứa này cũng được lưu trữ một cách liên tiếp  trong vector. Tuy nhiên, nếu như số lượng phần tử (size) của một mảng là cố định, thì ở vector, nó hoàn toàn có thể _thay đổi_ trong suốt quá trình làm việc của chương trình. 

📓 **Modifiers**
   1. **push_back()**: Hàm đẩy một phần tử vào vị trí sau cùng của vector. Nếu kiểu của đối tượng được truyền dưới dạng tham số trong push_back() không giống với kiểu 
của vector thì sẽ bị ném ra.
```ruby
ten-vector.push_back(ten-cua-phan-tu);
```
   
2. **assign()**: Nó gán một giá trị mới cho các phần tử vector bằng cách thay thế các  giá trị cũ.
```ruby  
ten-vector.assign(int size, int value);
```   
   
3. **pop_back()**: Hàm pop_back () được sử dụng để xóa đi phần tử cuối cùng một vector.
```ruby
ten-vector.pop_back();   
```  
   
4. **insert()**: Hàm này chèn các phần tử mới vào trước phần tử trước vị trí được trỏ bởi vòng lặp. Chúng ta cũng có thể chuyển một số đối số thứ ba, đếm số lần phần tử được chèn vào trước vị trí được trỏ.
```ruby
ten-vector.insert(position, value);   
```    
   
5. **erase()**: Hàm được sử dụng để xóa các phần tử tùy theo vị trí vùng chứa
```ruby
ten-vector.erase(position);

ten-vector.erase(start-position, end-position);   
```      
   
6. **emplace()**: Nó mở rộng vùng chứa bằng cách chèn phần tử mới vào
```ruby
ten-vector.emplace(ten-vector.position, element);   
```   
   
7. **emplace_back()**: Nó được sử dụng để chèn một phần tử mới vào vùng chứa vector, phần tử mới sẽ được thêm vào cuối vector
```ruby
ten-vector.emplace_back(value);   
```    
   
8. **swap()**: Hàm được sử dụng để hoán đổi nội dung của một vector này với một vector khác cùng kiểu. Kích thước có thể khác nhau.
```ruby
ten-vector-1.swap(ten-vector-2);   
```      
   
9. **clear()**: Hàm được sử dụng để loại bỏ tất cả các phần tử của vùng chứa vector
```ruby
ten-vector.clear();  
``` 

</details>



##

### 💊 VĐK

<details>

<summary> 🔸 SPI</summary>

Visit tutorial: https://www.corelis.com/education/tutorials/spi-tutorial/   
   
👉**Giới thiệu**
   
>  - Giao tiếp ngoại vi nối tiếp hoặc SPI (Serial Peripheral Interface) là một chuẩn đồng bộ nối tiếp để truyền dữ liệu ở chế độ song công toàn phần (full – duplex) tức trong cùng một thời điểm có thể xảy ra đồng thời quá trình truyền và nhận.
> - Giao tiếp ngoại vi nối tiếp (SPI) là một loại giao thức kiểu Master – Slave cung cấp một giao diện chi phí đơn giản và chi phí thấp giữa vi điều khiển và các thiết bị ngoại vi của nó.
> - SPI thường được sử dụng giao tiếp với bộ nhớ EEPROM, RTC (Đồng hồ thời gian thực), IC âm thanh, các loại cảm biến như nhiệt độ và áp suất, thẻ nhớ như MMC hoặc thẻ SD hoặc thậm chí các bộ vi điều khiển khác.
> - Là giao tiếp đồng bộ, bất cứ quá trình nào cũng đều được đồng bộ với xung clock sinh ra bởi thiết bị Master  ► Không cần phải lo lắng về tốc độ truyền dữ liệu.
   
![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/a1e3c512-ca02-419a-a168-592d21b73199)
   
👉**Hoạt động** 
   
![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/84fffb75-139f-41de-bdd8-a6d448919a01)
   
> - Trong giao thức SPI, có thể chỉ có một thiết bị Master nhưng nhiều thiết bị Slave.
> - Bus SPI bao gồm _4 tín hiệu hoặc chân_ . Chúng là:
>> - Master – Out / Slave – In ( **MOSI** hay **SI**): cổng ra của bên Master, cổng vào của bên Slave, dành cho việc truyền dữ liệu từ thiết bị Master  đến thiết bị Slave .
>> - Master – In / Slave – Out ( **MISO** hay **SO**): cổng vào của bên Master, cổng ra của bên Slave, dành cho việc truyền dữ liệu từ thiết Slave đến thiết bị Master.
>> - Serial Clock (SCK hay SCLK): xung giữ nhịp cho giao tiếp SPI
>> - Chip Select (CS) hay Slave Select (SS): chọn chip, thường SS = 0 chỉ định Slave hoạt động
   
> ❗ Lưu ý: Mỗi thời điểm bất kì 1 Master chỉ giao tiếp 1 Slave nhưg do tốc độ nhanh nên khó phân biệt.
   
Cách truyền và nhận dữ liệu
   
   ![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/33333b74-f7da-48da-a887-a58c66c0f0d0)

   
> - Mỗi chip Master hay Slave sẽ có một thanh ghi dữ liệu 8 bit chứa dữ liệu cần gửi đi hoặc dữ liệu nhận về.
> - Cứ mỗi xung nhịp do Master tạo ra trên chân SCLK, một bit trong thanh ghi dữ liệu của Master được truyền qua Slave trên đường MOSI, đồng thời một bit trong thanh ghi dữ liệu của Slave cũng được truyền qua cho Master trên đường MISO.
> - _Cứ mỗi một xung nhịp của xung clock(chân SCLK kéo từ 0 lên 1 rồi về 0) tức là output, dữ liệu nó đã truyền đi xong, thì lúc này nó sẽ trỏ tới cái phần tử, data tiếp theo trong mảng rồi tiếp tục làm như v. (đại khái là sử dụng chân sclk để đồng bộ)._

Các chế độ hoạt động

> Có 4 chế độ hoạt động
   
   ![image](https://github.com/KhaNguyen-UTE/Embedded_Interview/assets/84505849/983fbaac-31a7-4459-a5af-83bb2c0875e9)

</details>  





# Embedded-interview-Learning
  Embedded interview Learning
    **C**
  - SPI: https://1drv.ms/v/s!AjGzMBmvprJyjqx_MRWqfKaTlgm1rw?e=cUFYHr