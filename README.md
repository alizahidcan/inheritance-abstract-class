# Application to Read and Process Vitality Values in C

This application will be developed in the Mingw environment using the C language. When the application runs, it will read a file named `Veri.txt` containing numerical values between 0 and 100 arranged in rows and columns. These numerical values indicate vitality levels. The vitality levels are as follows:

- **Plant:** 1-9
- **Insect:** 10-20
- **Fly:** 21-50
- **Flea:** 51-99

Our application will be designed with a specific inheritance hierarchy, and all living beings will have a value to be printed on the screen. The inheritance hierarchy and the values to be printed for each living being are as follows:

## Inheritance Hierarchy
- LivingBeing
  - Plant
  - Insect
    - Fly
    - Flea

## Values to be Printed
- **Plant:** B
- **Insect:** C
- **Fly:** S
- **Flea:** P

Based on this information, numbers will first be read from the `Veri.txt` file, and variables will be created from the living beings. The initial state will be printed on the screen after being read. Once printed, pressing a key will start the process. The process will proceed from the first index to the end, and the eating patterns of the living beings are as follows:

- **Plant** → Flea
- **Insect** → Plant
- **Fly** → Flea
- **Plant** → Fly
- **Fly** → Insect
- **Insect** → Flea

If the same type of living being encounters each other, the one with the smaller numerical value will die, and if the numerical values are equal, the one closer to the end will die.

Once all processes are completed, the winning living being and its position will be printed on the screen, and the operations will end. The most important requirement of the application is that it should be implemented with object-oriented simulation. The minimum required structures are as follows:

- LivingBeing (Canli.h, Canli.c)
- Plant (Bitki.h, Bitki.c)
- Insect (Bocek.h, Bocek.c)
- Fly (Sinek.h, Sinek.c)
- Flea (Pire.h, Pire.c)
- Habitat (Habitat.h, Habitat.c)
- Test.c

## Installation and Running

1. Clone the project:
   ```sh
   git clone <repo-url>
   cd <repo-directory>

2. Install the requirements and compile the project:
   mingw32-make

3. Run the application:
   ./canlilar

4. Ensure the Veri.txt file is present and correctly formatted.



# Canlılık Değerlerini Okuyan ve İşleyen C Uygulaması

Bu uygulama, Mingw ortamında hazırlanacak ve C dilinde yazılacaktır. Uygulama çalıştığında, içerisinde satır ve sütun şeklinde 0 ve 100 arasındaki sayıların bulunduğu `Veri.txt` dosyası okunacak olup, bu sayısal değerler canlılık değerlerini belirtecektir. Canlılık değerleri şu şekildedir:

- **Bitki:** 1-9
- **Böcek:** 10-20
- **Sinek:** 21-50
- **Pire:** 51-99

Uygulamamız, belirli bir kalıtım hiyerarşisi ile yapılacak ve tüm canlıların ekrana yazılacak bir değeri olacaktır. Kalıtım hiyerarşisi ve canlıların ekrana yazılacak değerleri şu şekildedir:

## Kalıtım Hiyerarşisi
- Canlı
  - Bitki
  - Böcek
    - Sinek
    - Pire

## Ekrana Yazılacak Değerler
- **Bitki:** B
- **Böcek:** C
- **Sinek:** S
- **Pire:** P

Bu bilgiler doğrultusunda, ilk olarak `Veri.txt` dosyasından sayılar okunup canlılardan değişken oluşturulacaktır. Okunduktan sonraki ilk durum ekrana basılacaktır. Ekrana yazıldıktan sonra bir tuşa basıldığında süreç başlayacaktır. Süreç ilk indexten sona doğru ilerleyecek olup canlıların birbirini yeme şekli şu şekildedir:

- **Bitki** → Pire
- **Böcek** → Bitki
- **Sinek** → Pire
- **Bitki** → Sinek
- **Sinek** → Böcek
- **Böcek** → Pire

Eğer aynı canlı denk gelirse sayısal değeri küçük olan ölecektir ve eğer ki sayısal değer de eşit olursa bitiş noktasına yakın olan ölecektir.

Tüm işlemler bitince kazanan canlı ve konumu ekrana çıktı olarak bastırılıp işlemler bitecektir. Uygulamanın en önemli gerekliliği, nesne yönelimli benzetim ile yapılmasıdır. Bulunması gereken minimum yapılar şu şekildedir:

- Canlı (Canli.h, Canli.c)
- Bitki (Bitki.h, Bitki.c)
- Böcek (Bocek.h, Bocek.c)
- Sinek (Sinek.h, Sinek.c)
- Pire (Pire.h, Pire.c)
- Habitat (Habitat.h, Habitat.c)
- Test.c

## Kurulum ve Çalıştırma

1. Projeyi klonlayın:
   ```sh
   git clone <repo-url>
   cd <repo-directory>

2. Gereksinimleri yükleyin ve projeyi derleyin:
   mingw32-make

3. Uygulamayı çalıştırın:
  ./canlilar

4. 'Veri.txt' dosyasının mevcut olduğundan ve doğru formatta olduğundan emin olun.
